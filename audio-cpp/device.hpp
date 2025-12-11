#pragma once

#include <string>
#include <miniaudio/miniaudio.h>

#include <cstdint>
#include <memory>

#include <audio-cpp/context.hpp>

namespace audio {

using device_id = ma_device_id;


class device {

public:
    device() = default;
    device(const device_config& p_config, context* p_context);

    ma_device* get_wrapped_object() { return &m_device; }

private:
    ma_device_config m_config;
    ma_device m_device;
};

};
