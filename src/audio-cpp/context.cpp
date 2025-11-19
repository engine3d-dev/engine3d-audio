#include <audio-cpp/context.hpp>
#include <audio-cpp/device.hpp>
#include <miniaudio/miniaudio.h>

namespace audio {

context::context() {
    m_config = ma_context_config_init();

    ma_context_init(NULL, 0, &m_config, &m_context);
}

std::span<device_info> context::enumerate_devices() {
    // safe to assume we should repopulate device list
    populate_device_list();

    // build list of device info
    std::vector<device_info> r;
    for (std::map<std::string, ma_device_id>::iterator it = m_device_list.begin();
         it != m_device_list.end(); it++) {
        r.push_back({ .name = it->first });
    }

    return r;
}

void context::populate_device_list() {
    // initialize stuff for miniaudio call
    ma_uint32 device_count;
    ma_device_info* playback_devices;
    ma_result result;

    result = ma_context_get_devices(&m_context, &playback_devices, &device_count, NULL, NULL);
    if (result != MA_SUCCESS) {
        throw std::runtime_error("error getting devices");
    }

    // destroy and rebuild device list
    m_device_list.clear();
    for (int i = 0; i < device_count; i++) {
        ma_device_info device = playback_devices[i];
        m_device_list.insert(std::make_pair(std::string(device.name), device.id));
    }
}

std::unique_ptr<device> context::create_device(const std::string& deviceName,
                                               const device_config& config)
{
    device_info newConfig = std::copy(config);
    newConfig.id = m_device_list[deviceName];
    return std::make_unique<device>(newConfig);
}

}; // namespace audio
