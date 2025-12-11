#include <audio-cpp/context.hpp>
#include <audio-cpp/device.hpp>
#include <audio-cpp/types.hpp>
#include <miniaudio/miniaudio.h>
#include <vector>

namespace audio {

context::context() {
    m_config = ma_context_config_init();

    ma_context_init(nullptr, 0, nullptr, &m_context);
}

std::vector<device_info> context::enumerate_devices() {
    // safe to assume we should repopulate device list
    populate_device_list();

    // build list of device info
    std::vector<device_info> r;
    for (std::map<std::string, ma_device_id>::iterator it = m_device_list.begin();
         it != m_device_list.end(); it++) {
        r.push_back({ 
            .name = it->first
        });
    }

    return r;
}

void context::populate_device_list() {
    // initialize stuff for miniaudio call
    ma_uint32 device_count;
    ma_device_info* playback_devices;
    ma_result result;

    result = ma_context_get_devices(&m_context,
                                    &playback_devices,
                                    &device_count,
                                    nullptr,
                                    nullptr);
    if (result != MA_SUCCESS) {
        throw new audio_exception(result);
    }

    // destroy and rebuild device list
    m_device_list.clear();
    for (int i = 0; i < device_count; i++) {
        ma_device_info device = playback_devices[i];
        m_device_list.insert(std::make_pair(std::string(device.name), device.id));
    }
}

ma_device_id context::get_id_for_device(const device_info& p_info) {
    return m_device_list[p_info.name];
}

}; // namespace audio
