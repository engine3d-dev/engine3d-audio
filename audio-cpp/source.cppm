module;

#include <vector>
#include <miniaudio/miniaudio.h>
#include <cstdint>
// #include <audio-cpp/sound.hpp>
// #include <audio-cpp/engine.hpp>

export module audio:source;

import :sound;
import :engine;

export namespace audio {

using source_index = uint32_t;

struct source_settings {
    bool spatial = false;
};

/**
 * @note Sound abstraction around the miniaudio API
 *
 */
class source {
public:
    source() = default;
    source(const source_settings& p_settings) {
    }

    /**
     * @brief Add a new sound to the spatialized source.
     * @param p_sound: The new sound to be added.
     * @returns The index of the sound, which can be later referenced to
     * interact with the newly added sound.
     */
    source_index add(sound p_sound) {

    }

    /**
     * @brief Play a specific sound that has been registered with the
     * spatialized source.
     * @param p_index: The index to the sound to be played, which has been
     * previously returned from the "add" function call.
     */
    void play(source_index p_index) {

    }

    /**
     * @brief Stop a specific sound that has been registered with the
     * spatialized source.
     * @param p_index: The index to the sound to be played, which has been
     * previously returned from the "add" function call.
     */
    void stop(source_index p_index) {

    }

    /**
     * @brief Get a pointer to the sound at a specific index.
     * @param p_index: The index to the sound, which has been previously
     * returned from the "add" function call.
     * @returns A pointer to the sound at the specified index.
     */
    sound* get_sound(source_index p_index) { return &m_sounds.at(p_index); }

    /**
     * @brief Stop all currently playing sounds.
     */
    void stop_all() {

    }

    /**
     * @brief Initialize the spatialized source.
     */
    void init(engine* p_engine);


    void update(engine* p_engine);


    void uninit();

    // NOTE: any object with a spatialized_source should also have a transform;
    // otherwise, it will behave as a regular source
    void set_transform(float p_x, float p_y, float p_z, float p_forward_x, float p_forward_y, float p_forward_z) {
    }

    void set_velocity(float p_linear_velocity_x, float p_linear_velocity_y, float p_linear_velocity_z,
                      float p_angular_velocity_x, float p_angular_velocity_y, float p_angular_velocity_z) {
    }

private:
    void cleanup();

    std::vector<sound> m_sounds;

};

}; // namespace audio
