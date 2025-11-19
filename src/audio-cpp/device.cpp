#include <audio-cpp/device.hpp>

namespace audio {

device::device(const device_config& config) {
    m_config = ma_device_config_init(config.type);
}

};
