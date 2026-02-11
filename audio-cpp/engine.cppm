module;
#include <cstdint>
#include <miniaudio/miniaudio.h>

export module audio:engine;

import :types;
import :context;
import :device;
import :listener;

export namespace audio {

using listener_index = uint32_t;

struct engine_config {
    device_config device;

    // spatialization params
    unsigned int spatial_interpolation_ms = 50;
};

// forward declaration to avoid dependency cycle
class source;

class engine {

public:
    engine() = default;
    // engine(const engine_config& p_config,
    //        flecs::world& p_registry,
    //        context* p_context);
    engine(const engine_config& p_config, context* p_context);
    ~engine();

    void init();

    void update();

    void uninit();

    void set_active_listener(const listener* p_listener) { m_active_listener = p_listener; }

    ma_engine* get_instance() { return &m_engine; }

private:

    void set_listener_transform(listener_index p_index, float p_x, float p_y, float p_z, float p_forward_x, float p_forward_y, float p_forward_z) {
        // ma_engine_set_listener_transform(&m_engine, p_index, p_x, p_y, p_z, p_forward_x, p_forward_y, p_forward_z);
    }

    // void set_listener_velocity(listener_index p_index,
    //                            glm::vec3 p_linear_velocity,
    //                            glm::vec3 p_angular_velocity) {
    void set_listener_velocity(listener_index p_index,
                               float p_linear_velocity_x, float p_linear_velocity_y, float p_linear_velocity_z,
                               float p_angular_velocity_x, float p_angular_velocity_y, float p_angular_velocity_z) {
        // ma_engine_set_listener_velocity(&m_engine, p_index,
        //                                p_linear_velocity_x, p_linear_velocity_y, p_linear_velocity_z,
        //                                p_angular_velocity_x, p_angular_velocity_y, p_angular_velocity_z);
    }

    ma_engine m_engine;
    ma_engine_config m_config;

    device m_device;
    ma_context m_context;

    const listener* m_active_listener = nullptr;

    bool m_initialized = false;

    ma_engine_config m_engine_config;
};

};
