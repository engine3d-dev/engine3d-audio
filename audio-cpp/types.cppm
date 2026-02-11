module;

#include <miniaudio/miniaudio.h>
#include <exception>
#include <string>
#include <sstream>

export module audio:types;

export namespace audio {

enum device_type {
    playback = ma_device_type_playback,
    capture = ma_device_type_capture,
    duplex = ma_device_type_duplex,
    loopback = ma_device_type_loopback
};

// DEVICE CONFIGURATION TYPES
struct device_info {
    std::string name;
    device_type type;
};

struct device_config {
    device_info info;
    device_type type = device_type::playback;
    uint32_t sample_rate = 44100;
    uint32_t period_size_in_frames = 1024;
};

// SOUND CONFIGURATION TYPES
enum sound_type {
    from_file
};

struct sound_properties {
    sound_type type = sound_type::from_file;
    std::string filename;
    // NOTE: supporting data callbacks will require more work to fully abstract
    // void* data_callback(void) = nullptr;
    bool persistent = false;
    bool consider_position = false;
    bool consider_rotation = false;
    bool consider_velocity = false;
    bool decode_on_init = false;
    float gain = 1.f;
    float doppler_factor = 0.f;
    int polyphonic_voices = 1;
};

class audio_exception : public std::exception {
public:
    audio_exception(ma_result result) 
        : std::exception()
    {
        std::stringstream err_msg;
        err_msg << "miniaudio error code " << static_cast<unsigned int>(result);
        m_err_msg = err_msg.str();
    }

    [[nodiscard]] const char* what() const noexcept override {
        return m_err_msg.c_str();
    }

private:
    std::string m_err_msg;
};

};      // namespace audio
