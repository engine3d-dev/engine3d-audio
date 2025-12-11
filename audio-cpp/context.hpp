#pragma once

#include <vector>
#include <map>
#include <memory>

#include <audio-cpp/types.hpp>

namespace audio {

struct context_config {

};

/**
* @brief Low-level audio context for setting up miniaudio
*/
class context {

public:
    context();

    std::vector<device_info> enumerate_devices();

    ma_context* get_wrapped_object() { return &m_context; }

    ma_device_id get_id_for_device(const device_info& info);

private:

    ma_context m_context;
    ma_context_config m_config;

    std::map<std::string, ma_device_id> m_device_list;

    void populate_device_list();
};

}; // namespace audio
