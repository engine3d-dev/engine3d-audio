#pragma once
#include <physics/components.hpp>
#include <core/scene/components.hpp>
#include <audio-cpp/types.hpp>
#include <audio-cpp/context.hpp>
#include <audio-cpp/device.hpp>
#include <audio-cpp/listener.hpp>
#include <miniaudio/miniaudio.h>
#include <flecs.h>

namespace audio {

using listener_index = uint32_t;

struct engine_config {
    device_config device;

    // spatialization params
    unsigned int spatial_interpolation_ms;
};

// forward declaration to avoid dependency cycle
class source;

class engine {

public:
    engine(const engine_config& p_config,
           flecs::world& p_registry,
           context* p_context);

    void init();

    void update();

    void uninit();

    void set_active_listener(listener* p_listener);

    ma_engine* get_instance() { return &m_engine; }

private:

    void set_listener_transform(listener_index p_index,
                                const atlas::transform& p_transform);

    void set_listener_velocity(listener_index p_index,
                               glm::vec3 p_linear_velocity,
                               glm::vec3 p_angular_velocity);

    flecs::world* m_registry;

    flecs::query<source> m_query_source;
    flecs::query<source, atlas::transform> m_query_source_transform;
    flecs::query<source, atlas::physics_body> m_query_source_velocity;
    flecs::query<listener, atlas::transform> m_query_listener_transform;
    flecs::query<listener, atlas::physics_body> m_query_listener_velocity;

    ma_engine m_engine;
    ma_engine_config m_config;

    device* m_device = nullptr;
    context* m_context = nullptr;

    listener* m_active_listener = nullptr;
};

};
