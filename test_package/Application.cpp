#define MINIAUDIO_IMPLEMENTATION
#include <audio/internal/miniaudio.h>
using namespace std;

void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
    // In playback mode copy data to pOutput. In capture mode read data from pInput. In full-duplex mode, both
    // pOutput and pInput will be valid and you can move data from pInput into pOutput. Never process more than
    // frameCount frames.
}


/**
 * Demo example to check if audio devices/engine are instantiated correctly.
*/

int main(){
    ma_engine engine;
    ma_engine_config engine_config = ma_engine_config_init();

    // if(!engine_config){
    //     printf("Engine_Config did not init correctly!\n");
    //     return -1;
    // }
    // else{
    //     printf("Yaaay! This Engine_Config worked!\n");
    // }

    ma_result result = ma_engine_init(&engine_config, &engine);

    if(result != MA_SUCCESS){
        printf("MA_ENGINE did not init correctly!\n");
        return -1;
    }
    else{
        printf("Yaaay! This MA_ENGINE is working!\n");
    }

    ma_device_config config = ma_device_config_init(ma_device_type_playback);
    config.playback.format   = ma_format_f32;   // Set to ma_format_unknown to use the device's native format.
    config.playback.channels = 2;               // Set to 0 to use the device's native channel count.
    config.sampleRate        = 48000;           // Set to 0 to use the device's native sample rate.
    config.dataCallback      = data_callback;   // This function will be called when miniaudio needs more data.
    // config.pUserData         = pMyCustomData;   // Can be accessed from the device object (device.pUserData).

    ma_device device;
    if (ma_device_init(NULL, &config, &device) != MA_SUCCESS) {
        printf("This means miniaudio failed to initialize current platform device!\n");
        return -1;  // Failed to initialize the device.
    }
    else{
        printf("Validated the miniaudio framework has been tested if it works!\n");
    }

    ma_device_start(&device);     // The device is sleeping by default so you'll need to start it manually.

    // Do something here. Probably your program's main loop.

    ma_device_uninit(&device);
}
