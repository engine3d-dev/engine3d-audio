#pragma once

#include <miniaudio/miniaudio.h>

namespace audio {

class listener {
public:
    listener() = default;

    void set_ma_index(ma_uint32 p_index) { m_ma_index = p_index; }
    [[nodiscard]] ma_uint32 get_ma_index() const { return m_ma_index; }

private:
    ma_uint32 m_ma_index;
};

};
