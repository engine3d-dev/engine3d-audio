#pragma once

#include <string>
#include <miniaudio/miniaudio.h>

#include <stdint.h>

namespace audio {

// not interested in manually configuring this yet, but likely will be in the future...
struct resource_manager_config {

};

class resource_manager {

public:
    resource_manager();

private:
    ma_resource_manager m_rm;
    ma_resource_manager_config m_rm_config;

};

};
