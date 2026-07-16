#include <iostream>
#include <print>
#include <span>
#include <miniaudio/miniaudio.h>
import audio;
using namespace std;

int
main() {
    audio::context test_context;

    std::span<audio::playback_device> devices = test_context.enumerate_playback_devices();
    std::println("Playback Devices: {}", devices.size());

    // Reference to this specific audio device
    audio::playback_device* default_device = nullptr;
    for(audio::playback_device& device : devices) {
        // We set our current playback to be the defaulted playback audio
        if(device.is_default()) {
            std::println("Device Name: {}", device.name());
            default_device = &device;
        }
    }

    if(default_device != nullptr) {
        std::println("Audio Playback Device != nullptr!!!");
    }


    // setting up miniaudio engine
    default_device->start();
    ma_engine_config config = ma_engine_config_init();
    config.pDevice = *default_device; // Connects engine to your selected device

    ma_engine engine_instance;
    std::println("ma_engine_init: {}", static_cast<int>(ma_engine_init(&config, &engine_instance)));

    std::println("ma_engine_start = {}", static_cast<int>(ma_engine_start(&engine_instance)));

    ma_sound mySound;
    // MA_SOUND_FLAG_DECODE allows for faster playback/seeking
    std::println("ma_sound_init_from_file: {}", static_cast<int>(ma_sound_init_from_file(&engine_instance, "Resources/rolling_ball_on_wood.mp3", MA_SOUND_FLAG_DECODE, NULL, NULL, &mySound)));
    // ma_sound_set_volume(&mySound, 5);
    std::println("ma_sound_start: {}", static_cast<int>(ma_sound_start(&mySound)));

    // Keep the app alive while playing
    while(true) {
        // const auto test2 = ma_sound_start(&mySound);
        int c = getchar();
        if (c == '\n') {
            break;
        }
    }

    ma_sound_uninit(&mySound);
    ma_engine_uninit(&engine_instance);
    // default_device->stop();
}
