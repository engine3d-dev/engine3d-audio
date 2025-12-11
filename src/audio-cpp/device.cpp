#include <audio-cpp/device.hpp>
#include <audio-cpp/context.hpp>
#include <audio-cpp/types.hpp>
#include <string>

namespace audio {

device::device(const device_config& p_config,
               context* p_context) {
    m_config = ma_device_config_init(static_cast<ma_device_type>(p_config.type));
    m_config.sampleRate = p_config.sample_rate;
    m_config.periodSizeInFrames = p_config.period_size_in_frames;
    m_config.playback.channels = 2;

    ma_device_id new_id = p_context->get_id_for_device(p_config.info);
    m_config.playback.pDeviceID = &new_id;

    ma_result result = ma_device_init(p_context->get_wrapped_object(),
                                      &m_config,
                                      &m_device);
    if (result != MA_SUCCESS) {
        std::printf("could not initialize device; error %d\n", result);
        throw new audio_exception(result);
    }
}

};
