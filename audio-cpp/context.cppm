module;

#include <miniaudio/miniaudio.h>
#include <print>
#include <vector>
#include <span>

export module audio:context;

import :device;

export namespace audio {
    
    class context {
    public:
        context() {
            const auto res = ma_context_init(nullptr, 0, nullptr, &m_context);

            if(res != MA_SUCCESS) {
                std::println("ma_context_init failed with {}", static_cast<int>(res));
                return;
            }
        }

        ~context() = default;


        std::span<audio::playback_device> enumerate_playback_devices() {
            uint32_t device_count;
            ma_device_info* playback_devices;
            ma_device_id id;
            ma_result result = ma_context_get_devices(&m_context, &playback_devices, &device_count, nullptr, nullptr);

            m_playback_devices.reserve(device_count);

            if(result != MA_SUCCESS) {
                return {};
            }

            for(size_t i = 0; i < device_count; i++) {
                audio::device_params params = {
                    .is_default = static_cast<bool>(playback_devices[i].isDefault)
                };

                m_playback_devices.emplace_back(&m_context, playback_devices[i].name, playback_devices[i].id, params);
            }

            return m_playback_devices;
        }


    private:
        ma_context m_context;
        
        std::vector<audio::playback_device> m_playback_devices;
    };

};