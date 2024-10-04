#pragma once
#include <cstdint>

namespace audio{
    /**
     * @name decoder
     * @note Custom decoder for decoding audio data.
    */
    class decoder{
    public:

        //! @note users should not be able to create a non-init decoder
        decoder() = delete;

        /**
         * @param format defines the sample format
        */
        decoder(uint32_t format, uint32_t channels, uint32_t sample_rate);
        
        /**
         * @param device_config is to set the device_config for the decoder
        */
        decoder(uint32_t device_config);
    // private:
    };
};
