module;

#include <cstdint>
#include <miniaudio/miniaudio.h>
export module audio:device;

import :types;

export namespace audio {

    struct device_params {
        uint32_t sample_rate;
        uint32_t channels;
        uint32_t format;
    };

    /**
     * @brief Construct a playback audio device
     * 
     */
    class playback_device {
    public:
        /**
         * @brief Removes ability to construct an empty playback device object
         */
        playback_device() = delete;

        /**
         * @brief Construct a new playback device object
         *
         * @note This constructor will create a playback device with the default context
         * and the provided parameters. If the device fails to initialize, the object will be marked as invalid.
         *
         * Constructing a playback device manually by specifying the parameters allows for more control over the audio configuration, such as sample rate, channels, and format.
         *
         * @param p_params The parameters for the playback device, including sample rate, channels, and format.
         */
        playback_device(device_type const p_device_type, const device_params& p_params) {
            m_audio_device_config = ma_device_config_init(static_cast<ma_device_type>(p_device_type));
            m_audio_device_config.playback.format = static_cast<ma_format>(p_params.format);
            m_audio_device_config.playback.channels = p_params.channels;
            m_audio_device_config.sampleRate = p_params.sample_rate;

            auto res = ma_device_init(
                nullptr, &m_audio_device_config, &m_audio_device_handler);
            if (res != MA_SUCCESS) {
                reset();
                m_is_valid = false;
            }
            
            m_is_valid = true;
        }

        /**
         * @brief Construct a new playback device object with the audio context specified
         *
         * This constructor will create a playback device with the provided context and parameters.
         * If the device fails to initialize, the object will be marked as invalid.
         *
         * @param p_context
         * @param p_params
         */
        playback_device(ma_context* p_context, const device_params& p_params) {
            m_audio_device_config = ma_device_config_init(ma_device_type_playback);
            m_audio_device_config.playback.format = static_cast<ma_format>(p_params.format);
            m_audio_device_config.playback.channels = p_params.channels;
            m_audio_device_config.sampleRate = p_params.sample_rate;

            auto res = ma_device_init(
                p_context, &m_audio_device_config, &m_audio_device_handler);
            if (res != MA_SUCCESS) {
                reset();
                // TODO: Throw an exception here.
                m_is_valid = false;
                return;
            }

            m_is_valid = true;
        }

        ~playback_device() {
            reset();
        }

        [[nodiscard]] bool validate() const {
            return m_is_valid;
        }

        /**
         * @brief Start the playback device. If the device fails to start, it will be reset and marked as invalid.
         */
        void start() {
            auto res = ma_device_start(&m_audio_device_handler);
            if (res != MA_SUCCESS) {
                reset();
            }
        }

        /**
         * @brief Stop the playback device. If the device fails to stop, it will be reset and marked as invalid.
         */
        void stop() {
            auto res = ma_device_stop(&m_audio_device_handler);
            if (res != MA_SUCCESS) {
                reset();
            }
        }

        // Implicit conversion operators to allow using the playback_device object directly as a ma_device pointer or reference
        operator ma_device*() {
            return &m_audio_device_handler;
        }

        // Implicit conversion operator to allow using the playback_device object directly as a ma_device reference
        operator ma_device&() {
            return m_audio_device_handler;
        }

    private:
        /**
         * @brief Reset the playback device and mark it as invalid.
         *
         * This function uninitializes the underlying audio device and marks the playback_device object as invalid.
         */
        void reset() {
            ma_device_uninit(&m_audio_device_handler);
        }
    private:
        bool m_is_valid=false;
        ma_device m_audio_device_handler;
        ma_device_config m_audio_device_config;
        ma_device_info m_audio_device_info;
    };



};
