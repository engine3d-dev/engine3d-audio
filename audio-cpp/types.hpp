#pragma once

#include <miniaudio/miniaudio.h>
#include <exception>
#include <string>
#include <sstream>

namespace audio {

class audio_exception : public std::exception {
public:
    audio_exception(ma_result result) 
        : std::exception()
    {
        std::stringstream err_msg;
        err_msg << "miniaudio error code " << static_cast<unsigned int>(result);
        m_err_msg = err_msg.str();
    }

    const char* what() const noexcept override {
        return m_err_msg.c_str();
    }

private:
    std::string m_err_msg;
};

};      // namespace audio
