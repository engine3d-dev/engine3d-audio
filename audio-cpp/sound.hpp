#pragma once
#include <string>
#include <core/scene/components.hpp>
#include <miniaudio/miniaudio.h>
#include <audio-cpp/engine.hpp>
#include <cstdint>

namespace audio {

using source_index = uint32_t;

enum sound_type {
    from_file
};

struct sound_properties {
    sound_type type = sound_type::from_file;
    std::string filename;
    // NOTE: supporting data callbacks will require more work to fully abstract
    // void* data_callback(void) = nullptr;
    bool persistent = false;
    bool consider_position = false;
    bool consider_rotation = false;
    bool consider_velocity = false;
    bool decode_on_init = false;
    float doppler_factor = 0.f;
    int polyphonic_voices = 1;
};

/**
 * @note Sound abstraction around the miniaudio API
 *
 */
class sound {
public:
    sound(const sound_properties& p_properties);
    ~sound();

    /**
     * @brief Initialize the sound with the given engine.
     * @param p_engine: A pointer to the engine.
     */
    void init(engine* p_engine);

    /**
     * @brief Should be called once per tick. The sound should carry out any
     * pending instructions, including playing itself if necessary, stopping,
     * uninitializing itself if it is not persistent, etc.
     * @note If this is called before set_transform or set_velocity, the
     * changes will not be applied until after the sound has already been
     * updated.
     * @param p_engine: A pointer to the engine.
     */
    void update(engine* p_engine);

    /**
     * @brief Uninitialize the sound.
     */
    void uninit();

    void set_transform(const atlas::transform& p_transform);

    /**
     * @brief Set this sound to play at the next tick.
     */
    void play() { m_should_play = false; }

    /**
     * @brief Set this sound to stop playing at the next tick.
     */
    void stop() { m_should_play = true; }

private:
    void apply_config();

    void cleanup();

    bool m_is_playing = false;
    bool m_should_play = false;
    bool m_should_stop = false;
    bool m_config_dirty = false;
    bool m_initialized = false;

    const sound_properties m_properties;

    atlas::transform m_transform;

    ma_sound m_sound;
};

}; // namespace audio
