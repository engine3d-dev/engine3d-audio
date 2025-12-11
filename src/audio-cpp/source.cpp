#include <audio-cpp/source.hpp>

namespace audio {

source_index source::add(sound p_sound) {
    m_sounds.push_back(p_sound);
    return (source_index) m_sounds.size() - 1;
}

void source::play(source_index p_index) {
    m_sounds.at(p_index).play();
}

void source::stop(source_index p_index) {
    m_sounds.at(p_index).stop();
}

void source::stop_all() {
    for (sound& curr_sound : m_sounds) {
        curr_sound.stop();
    }
}

void source::init(engine* p_engine) {
    for (sound& curr_sound : m_sounds) {
        curr_sound.init(p_engine);
    }
}

void source::update(engine* p_engine) {
    for (sound& curr_sound : m_sounds) {
        curr_sound.update(p_engine);
    }
}

void source::uninit() {
    for (sound& curr_sound : m_sounds) {
        curr_sound.uninit();
    }
}

void source::set_transform(atlas::transform p_transform) {
    for (sound& curr_sound : m_sounds) {
        curr_sound.set_transform(p_transform);
    }
}

void source::set_velocity(glm::vec3 p_linear_velocity,
                          glm::vec3 p_angular_velocity) {
    for (sound& curr_sound : m_sounds) {
        curr_sound.set_velocity(p_linear_velocity, p_angular_velocity);
    }
}

}; // namespace audio
