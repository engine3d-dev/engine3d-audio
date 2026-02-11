module;

#include <cstdint>
#include <miniaudio/miniaudio.h>

export module audio:types;


export namespace audio {

    // This is a copy of the ma_format enum from miniaudio, but with a more C++-friendly name and style.
    enum class format : uint8_t {
        unknown = 0, // ma_format_unknown
        u8 = 1,     // ma_format_u8
        s16 = 2,    // ma_format_s16
        s24 = 3,    // ma_format_s24
        s32 = 4,    // ma_format_s32
        f32 = 5     // ma_format_f32
    };

    /** A list of standard sample rates. */
    /* Standard rates need to be in priority order. */
    enum class sample_rate : uint32_t {
        /** Most Common */
        r48000 = 48000,     // ma_standard_sample_rate_48000
        r44100 = 44100,     // ma_standard_sample_rate_44100

        /** Lows */
        r32000 = 32000,     // ma_standard_sample_rate_32000
        r24000 = 24000,     // ma_standard_sample_rate_24000
        r22050 = 22050,     // ma_standard_sample_rate_22050

        /** Highs */
        r88200 = 88200,     // ma_standard_sample_rate_88200
        r96000 = 96000,     // ma_standard_sample_rate_96000
        r176400 = 176400,   // ma_standard_sample_rate_176400
        r192000 = 192000,   // ma_standard_sample_rate_192000

        /** Extreme lows */
        r16000 = 16000,     // ma_standard_sample_rate_16000
        r11025 = 11025,     // ma_standard_sample_rate_11025
        r8000 = 8000,       // ma_standard_sample_rate_8000

        /** Extreme highs */
        r352800 = 352800,   // ma_standard_sample_rate_352800
        r384000 = 384000,   // ma_standard_sample_rate_384000

        rate_min = r8000,   // ma_standard_sample_rate_min
        rate_max = r384000, // ma_standard_sample_rate_max
        rate_count = 14     // ma_standard_sample_rate_count
    };
};