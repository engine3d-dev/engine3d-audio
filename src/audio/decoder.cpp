#include <audio/decoder.h>
#include <miniaudio.h>

namespace audio{
    static ma_decoder g_Decoder;
    static ma_device_config g_DeviceConfig;
    static ma_device g_Device;

    decoder::decoder(uint32_t format, uint32_t channels, uint32_t sample_rate){

    }

    decoder::decoder(uint32_t device_config){
        g_DeviceConfig.playback.format = g_Decoder.outputFormat;
        g_DeviceConfig.playback.channels = g_Decoder.outputChannels;
        g_DeviceConfig.sampleRate = g_Decoder.outputSampleRate;
        g_DeviceConfig.dataCallback = [](ma_device* p_Device, void* p_Output, const void* p_Input, uint32_t p_FrameCount){
            ma_decoder* decoder = (ma_decoder*)p_Device->pUserData;

            if(!decoder){
                return;
            }

            // ma_decoder_read_pcm_frames()
        };
    }
};
