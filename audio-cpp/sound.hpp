#pragma once

#include <string>
#include <core/scene/components.hpp>
#include <miniaudio/miniaudio.h>
#include <audio-cpp/engine.hpp>
#include <audio-cpp/types.hpp>
#include <cstdint>

namespace audio {

using source_index = uint32_t;

/**
 * @note Sound abstraction around the miniaudio API
 *
 */
class sound {
public:
    sound() = default;
    sound(const sound_properties& p_properties);

    ~sound() {
        if (m_initialized) {
            uninit();
        }
    }

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

    void set_velocity(const glm::vec3& p_linear_velocity,
                      const glm::vec3& p_angular_velocity);

    /**
     * @brief Set this sound to play at the next tick.
     */
    void play() { m_should_play = true; }

    /**
     * @brief Set this sound to stop playing at the next tick.
     */
    void stop() { m_should_stop = true; }

private:
    void apply_config();

    void cleanup();

    bool m_is_playing = false;
    bool m_should_play = false;
    bool m_should_stop = false;
    bool m_config_dirty = false;
    bool m_initialized = false;

    sound_properties m_properties;

    atlas::transform m_transform;
    glm::vec3 m_linear_velocity;
    glm::vec3 m_angular_velocity;

    ma_sound m_sound;
};

}; // namespace audio
