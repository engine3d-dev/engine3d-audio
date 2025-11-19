#include <audio-cpp/sound.hpp>
#include <miniaudio/miniaudio.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace audio {

sound::sound(const sound_properties& p_properties)
    : m_properties(p_properties)
{

}

void sound::init(engine* p_engine) {
    if (m_initialized) {
        return;
    }

    // get raw ma_engine instance
    ma_engine* engine_inst = p_engine->get_instance();

    ma_result result;
    switch (m_properties.type) {
        case sound_type::from_file:
            int cfg_flags = 0;
            if (m_properties.decode_on_init) {
                cfg_flags |= MA_SOUND_FLAG_DECODE;
            }

            result = ma_sound_init_from_file(engine_inst,
                                             m_properties.filename.c_str(),
                                             cfg_flags,
                                             NULL,
                                             NULL,
                                             &m_sound);
            break;

        //case sound_type::from_callback:
        //    // TODO: program this
        //    break;
    }

    if (result != MA_SUCCESS) {
        throw new audio_exception(result);
    }

    m_initialized = true;
}

void sound::apply_config() {
    if (!m_initialized) {
        return;
    }

    ma_sound_set_doppler_factor(&m_sound, m_properties.doppler_factor);
}

void sound::update(engine* p_engine) {
    // reload config if necessary
    if (m_config_dirty) {
        apply_config();
    }

    bool was_playing = m_is_playing;
    m_is_playing = ma_sound_is_playing(&m_sound);

    if (m_is_playing && m_should_stop) {
        ma_sound_stop(&m_sound);
        m_is_playing = false;
    }

    // free resources if sound is not persistent and has ended
    if (!m_properties.persistent && was_playing && !m_is_playing) {
        uninit();
    }

    // the interpolation of this value cannot be controlled on a sound-by-sound
    // basis yet, but may be if each sound is eventually given its own spatial-
    // izer. for now, it will be interpolated according to engine_config's var
    // spatial_interpolation_ms.
    if (m_properties.consider_position) {
        glm::highp_vec3 position = m_transform.position;
        ma_sound_set_position(&m_sound, position.x, position.y, position.z);
    }

    if (m_properties.consider_rotation) {
        glm::quat quaternion = atlas::to_quat(m_transform.quaternion);
        glm::vec3 forward = quaternion * glm::vec3(0.0f, 0.0f, -1.0f);
        ma_sound_set_direction(&m_sound, forward.x, forward.y, forward.z);
    }

    if (m_properties.consider_velocity) {
        // TODO: give velocity to miniaudio
    }

    // play sound if we should play
    if (m_should_play) {
        if (!m_initialized) {
            init(p_engine);
        }

        // TODO: add playhead positioning
        // replace with ma_sound_seek_to_second, which cannot be included for
        // whatever reason...
        ma_sound_seek_to_pcm_frame(&m_sound, 0);
        if (!m_is_playing) {
            ma_sound_start(&m_sound);
            m_is_playing = true;
        }

        m_should_play = false;
    }
}

void sound::uninit() {
    if (m_initialized) {
        ma_sound_uninit(&m_sound);
        m_initialized = false;
    }
}

//    sound::sound(const std::string& p_filename) {
//        ma_decoder_init_file(p_filename.c_str(), nullptr, &m_decoder);
//
//        m_audio_device_config = ma_device_config_init(ma_device_type_playback);
//
//        m_audio_device_config.playback.format = m_decoder.outputFormat;
//        m_audio_device_config.playback.channels = m_decoder.outputChannels;
//        m_audio_device_config.sampleRate = m_decoder.outputSampleRate;
//        m_audio_device_config.dataCallback = data_callback;
//        m_audio_device_config.pUserData = &m_decoder;
//
//        auto res = ma_device_init(
//          nullptr, &m_audio_device_config, &m_audio_device_handler);
//        if (res != MA_SUCCESS) {
//            cleanup();
//            return;
//        }
//    }
//
//    sound::~sound() {
//        cleanup();
//    }
//
//    void sound::on_play() {
//        auto res = ma_device_start(&m_audio_device_handler);
//        if (res != MA_SUCCESS) {
//            cleanup();
//        }
//    }
//
//    void sound::on_stop() {
//        auto res = ma_device_stop(&m_audio_device_handler);
//
//        if (res != MA_SUCCESS) {
//            cleanup();
//        }
//    }
//
//    void sound::cleanup() {
//        ma_device_uninit(&m_audio_device_handler);
//        ma_decoder_uninit(&m_decoder);
//    }
};
