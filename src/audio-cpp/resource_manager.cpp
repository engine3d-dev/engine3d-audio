#include <audio-cpp/resource_manager.hpp>
#include <audio-cpp/types.hpp>

#include <string>
#include <miniaudio/miniaudio.h>

#include <stdint.h>

namespace audio {

resource_manager::resource_manager() {
    m_rm_config = ma_resource_manager_config_init();

    ma_result r = ma_resource_manager_init(&m_rm_config, &m_rm);
    if (r != MA_SUCCESS) {
        throw new audio_exception(r);
    }
}

resource_manager::resource_manager(resource_manager_config& config) {
    m_rm_config = ma_resource_manager_config_init();
    // set values according to config passed in

    ma_result r = ma_resource_manager_init(&m_rm_config, &m_rm);
    if (r != MA_SUCCESS) {
        // throw exception
    }
}

};
