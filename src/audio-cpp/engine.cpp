#include <physics/components.hpp>
#include <core/scene/components.hpp>
#include <audio-cpp/engine.hpp>
#include <audio-cpp/device.hpp>
#include <audio-cpp/types.hpp>
#include <audio-cpp/source.hpp>

namespace audio {

engine(const engine_config& p_config,
           flecs::world& p_registry,
           context* p_context)
    : m_context(p_context)
    , m_registry(&p_registry) {
    m_device = device(config.device);

    m_engine_config = ma_engine_config_init();
    m_engine_config.pContext = pContext->get_wrapped_object();
    m_engine_config.gainSmoothTimeInMilliseconds = p_config.spatial_interpolation_ms;

    ma_result result;

    result = ma_engine_init(&m_engine_config, &m_engine);
    if (result != MA_SUCCESS) {
        throw new audio_exception(result);
    }

    m_query_source = m_registry->query_builder<source>().build();
    m_query_source_transform =
        m_registry->query_builder<source, transform>().build();
    m_query_source_velocity =
        m_registry->query_builder<source, physics_body>().build();
}

void engine::init() {
    m_query_source.each([this] (flecs::entity p_entity,
                                source& p_source) {
        p_source.init(this);
    }
}

void engine::uninit() {
    m_query_source.each([this] (flecs::entity p_entity,
                                source& p_source) {
        p_source.uninit();
    }
}

void engine::update() {
    m_query_std_source.each([this] (flecs::entity p_entity,
                                    source& p_source) {
        p_source.update(this);
    });

    m_query_source_transform.each([this] (flecs::entity p_entity,
                                  source& p_source,
                                  atlas::transform& p_transform) {
        p_source.set_transform(p_transform);
    });

    m_query_source_velocity.each([this] (flecs::entity p_entity,
                                 source& p_source,
                                 atlas::physics_body& p_body) {
        p_source.set_velocity(p_body.linear_velocity, p_body.angular_velocity);
    });

    m_query_listener_transform.each([this] (flecs::entity p_entity,
                                    listener& p_listener,
                                    atlas::transform& p_transform) {
        if (&p_listener == m_active_listener) {
            // TODO: check whether we should be setting this stuff
            // (e.g., in config)
            glm::vec3 position = p_transform.position;
            ma_engine_listener_set_position(&m_engine,
                                            0,  // TODO: add support for internal MA listener indices
                                            position.x,
                                            position.y,
                                            position.z);

            glm::quat quaternion = atlas::to_quat(m_transform.quaternion);
            glm::vec3 forward = glm::rotate(quaternion,
                                            glm::vec3(0.0f, 0.0f, -1.0f));
            ma_engine_listener_set_direction(&m_sound,
                                             0, // TODO: add support for internal MA listener indices
                                             forward.x,
                                             forward.y,
                                             forward.z);
        }
    });

    m_query_listener_velocty.each([this] (flecs::entity p_entity,
                                  listener& p_listener,
                                  atlas::physics_body& p_body){

        if (&p_listener == m_active_listener) {

        }
    });
}

}; // namespace audio
