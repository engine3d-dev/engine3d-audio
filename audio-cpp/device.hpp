#pragma once

#include <string>
#include <miniaudio/miniaudio.h>

#include <stdint.h>

namespace audio {

using device_id = ma_device_id;

enum device_type {
    playback = ma_device_type_playback,
    capture = ma_device_type_capture,
    duplex = ma_device_type_duplex,
    loopback = ma_device_type_loopback
};

struct device_info {
    std::string name;
    device_type type;
    device_id id;
};

struct device_config {
    device_info info;
    uint32_t sampleRate;
    uint32_t periodSizeInFrames;
};

class device {

public:
    device();
    device(const device_config& config);

    ma_device* get_wrapped_object() { return &m_device; }

private:
    ma_device_config m_config;
    ma_device m_device;
};

};
