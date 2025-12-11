#include <physics/components.hpp>
#include <core/scene/components.hpp>
#include <core/engine_logger.hpp>
#include <glm/gtc/quaternion.hpp>
#include <audio-cpp/engine.hpp>
#include <audio-cpp/device.hpp>
#include <audio-cpp/types.hpp>
#include <audio-cpp/source.hpp>

namespace audio {

engine::engine(const engine_config& p_config,
           flecs::world& p_registry,
           context* p_context)
    : //m_context(p_context),
     m_registry(&p_registry)
    , m_device(p_config.device, p_context) {
    m_config = ma_engine_config_init();
    m_config.pContext = p_context->get_wrapped_object();
    //m_config.pDevice = m_device.get_wrapped_object();
    m_config.gainSmoothTimeInMilliseconds = p_config.spatial_interpolation_ms;

    ma_result result;

    result = ma_engine_init(&m_config, &m_engine);
    if (result != MA_SUCCESS) {
        std::printf("could not initialize engine; got error %d\n", result);
        throw new audio_exception(result);
    }

    std::printf("done with this engine constructor thing\n");

    m_initialized = false;

    //result = ma_context_init(nullptr, 0, nullptr, &m_context);
    //if (result != MA_SUCCESS) {
    //    return;
    //}

    //m_engine_config = ma_engine_config_init();
    //m_engine_config.pContext = &m_context;

    //    result = ma_engine_init(&m_engine_config, &m_engine);
    //    if (result != MA_SUCCESS) {
    //        std::printf("epic fail!!!!: %d\n", result);
    //        return;
    //    }

}

engine::~engine() {
    uninit();
    ma_engine_uninit(&m_engine);
}

void engine::init() {
    console_log_info("engine::init: start");

    m_query_source = m_registry->query_builder<source>().build();
    m_query_source_transform =
        m_registry->query_builder<source, atlas::transform>().build();
    m_query_source_velocity =
        m_registry->query_builder<source, atlas::physics_body>().build();
    m_query_listener_transform =
        m_registry->query_builder<listener, atlas::transform>().build();

    m_query_source.each([this] (flecs::entity p_entity,
                                source& p_source) {
        p_source.init(this);
    });

    m_initialized = true;

    console_log_info("engine::init: done");
}

void engine::uninit() {
    m_query_source.each([this] (flecs::entity p_entity,
                                source& p_source) {
        p_source.uninit();
    });

    m_initialized = false;
}

void engine::update() {
    //console_log_info("engine::update: start");

    if (!m_initialized) {
        return;
    }

    //console_log_info("engine::update: doing source query");
    m_query_source.each([this] (flecs::entity p_entity,
                                source& p_source) {
        p_source.update(this);
    });

    //console_log_info("engine::update: doing transform query");
    m_query_source_transform.each([this] (flecs::entity p_entity,
                                  source& p_source,
                                  atlas::transform& p_transform) {
        p_source.set_transform(p_transform);
    });

    //console_log_info("engine::update: doing physics_body query");
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

            glm::quat quaternion = atlas::to_quat(p_transform.quaternion);
            glm::vec3 forward = quaternion * glm::vec3(0.0f, 0.0f, -1.0f);
            ma_engine_listener_set_direction(&m_engine,
                                             0, // TODO: add support for internal MA listener indices
                                             forward.x,
                                             forward.y,
                                             forward.z);
        }
    });

    //m_query_listener_velocity.each([this] (flecs::entity p_entity,
    //                               listener& p_listener,
    //                               atlas::physics_body& p_body){

    //    if (&p_listener == m_active_listener) {
    //        ma_engine_listener_set_velocity(&m_engine,
    //                                        0,
    //                                        p_body.linear_velocity.x,
    //                                        p_body.linear_velocity.y,
    //                                        p_body.linear_velocity.z);
    //    }
    //});
    //
    //console_log_info("engine::update: done");
}

}; // namespace audio
