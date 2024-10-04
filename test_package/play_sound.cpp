#include <stdio.h>
#define MINIAUDIO_IMPLEMENTATION
#include <audio/internal/miniaudio.h>
using namespace std;

void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount){
    ma_decoder* pDecoder = (ma_decoder*)pDevice->pUserData;
    if (pDecoder == NULL) {
        return;
    }

    ma_decoder_read_pcm_frames(pDecoder, pOutput, frameCount, NULL);

    (void)pInput;
}

int main(int argc, char** argv){
    //! @note 
    ma_decoder decoder;
    ma_device_config device_config;
    ma_device device_handler;

    if (argc < 2) {
        printf("No input file.\n");
        return -1;
    }

    ma_result result = ma_decoder_init_file(argv[1], NULL, &decoder);

    if (result != MA_SUCCESS) {
        printf("Could not load file: %s\n", argv[1]);
        return -2;
    }

    device_config = ma_device_config_init(ma_device_type_playback);
    device_config.playback.format   = decoder.outputFormat;
    device_config.playback.channels = decoder.outputChannels;
    device_config.sampleRate        = decoder.outputSampleRate;
    // device_config.dataCallback      = data_callback;
    device_config.dataCallback = [](ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount){
        ma_decoder* pDecoder = (ma_decoder*)pDevice->pUserData;
        if (pDecoder == NULL) {
            return;
        }

        ma_decoder_read_pcm_frames(pDecoder, pOutput, frameCount, NULL);
    };
    device_config.pUserData         = &decoder;

    if (ma_device_init(NULL, &device_config, &device_handler) != MA_SUCCESS) {
        printf("Failed to open playback device.\n");
        ma_decoder_uninit(&decoder);
        return -3;
    }

    if (ma_device_start(&device_handler) != MA_SUCCESS) {
        printf("Failed to start playback device.\n");
        ma_device_uninit(&device_handler);
        ma_decoder_uninit(&decoder);
        return -4;
    }

    printf("Press Enter to quit...");
    getchar();

    ma_device_uninit(&device);
    ma_decoder_uninit(&decoder);

    return 0;
}
