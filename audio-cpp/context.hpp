#pragma once

#include <span>
#include <map>
#include <audio-cpp/device.hpp>

namespace audio {

struct context_config {

};

/**
* @brief Low-level audio context for setting up miniaudio
*/
class context {

public:
    context();

    std::span<device_info> enumerate_devices();

    void create_device(device* pDevice, const device_info& info);

    std::unique_ptr<device> create_device(const std::string& deviceName,
                                          const device_info& info);

    ma_context* get_wrapped_object() { return &m_context; }

private:

    ma_context m_context;
    ma_context_config m_config;

    std::map<std::string, ma_device_id> m_device_list;

    void populate_device_list();
};

}; // namespace audio
