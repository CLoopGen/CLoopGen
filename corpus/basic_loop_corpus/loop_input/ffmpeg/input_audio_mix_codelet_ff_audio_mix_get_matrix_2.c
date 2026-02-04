#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

enum AVOptionType {
    AV_OPT_TYPE_FLAGS,
    AV_OPT_TYPE_INT,
    AV_OPT_TYPE_INT64,
    AV_OPT_TYPE_DOUBLE,
    AV_OPT_TYPE_FLOAT,
    AV_OPT_TYPE_STRING,
    AV_OPT_TYPE_RATIONAL,
    AV_OPT_TYPE_BINARY,
    AV_OPT_TYPE_DICT,
    AV_OPT_TYPE_UINT64,
    AV_OPT_TYPE_CONST,
    AV_OPT_TYPE_IMAGE_SIZE,
    AV_OPT_TYPE_PIXEL_FMT,
    AV_OPT_TYPE_SAMPLE_FMT,
    AV_OPT_TYPE_VIDEO_RATE,
    AV_OPT_TYPE_DURATION,
    AV_OPT_TYPE_COLOR,
    AV_OPT_TYPE_CHANNEL_LAYOUT,
    AV_OPT_TYPE_BOOL
};

typedef struct AVRational {
    int num;
    int den;
} AVRational;

struct AVOption {
    const char *name;
    const char *help;
    int offset;
    enum AVOptionType type;
    union {
        int64_t i64;
        double dbl;
        const char *str;
        AVRational q;
    } default_val;
    double min;
    double max;
    int flags;
    const char *unit;
};

typedef enum {
    AV_CLASS_CATEGORY_NA = 0,
    AV_CLASS_CATEGORY_INPUT,
    AV_CLASS_CATEGORY_OUTPUT,
    AV_CLASS_CATEGORY_MUXER,
    AV_CLASS_CATEGORY_DEMUXER,
    AV_CLASS_CATEGORY_ENCODER,
    AV_CLASS_CATEGORY_DECODER,
    AV_CLASS_CATEGORY_FILTER,
    AV_CLASS_CATEGORY_BITSTREAM_FILTER,
    AV_CLASS_CATEGORY_SWSCALER,
    AV_CLASS_CATEGORY_SWRESAMPLER,
    AV_CLASS_CATEGORY_DEVICE_VIDEO_OUTPUT = 40,
    AV_CLASS_CATEGORY_DEVICE_VIDEO_INPUT,
    AV_CLASS_CATEGORY_DEVICE_AUDIO_OUTPUT,
    AV_CLASS_CATEGORY_DEVICE_AUDIO_INPUT,
    AV_CLASS_CATEGORY_DEVICE_OUTPUT,
    AV_CLASS_CATEGORY_DEVICE_INPUT,
    AV_CLASS_CATEGORY_NB
} AVClassCategory;

typedef struct AVClass {
    const char *class_name;
    const char *(*item_name)(void *);
    const struct AVOption *option;
    int version;
    int log_level_offset_offset;
    int parent_log_context_offset;
    void *(*child_next)(void *, void *);
    const struct AVClass *(*child_class_next)(const struct AVClass *);
    AVClassCategory category;
    AVClassCategory (*get_category)(void *);
    int (*query_ranges)(struct AVOptionRanges **, void *, const char *, int);
} AVClass;

enum AVSampleFormat {
    AV_SAMPLE_FMT_NONE = -1,
    AV_SAMPLE_FMT_U8,
    AV_SAMPLE_FMT_S16,
    AV_SAMPLE_FMT_S32,
    AV_SAMPLE_FMT_FLT,
    AV_SAMPLE_FMT_DBL,
    AV_SAMPLE_FMT_U8P,
    AV_SAMPLE_FMT_S16P,
    AV_SAMPLE_FMT_S32P,
    AV_SAMPLE_FMT_FLTP,
    AV_SAMPLE_FMT_DBLP,
    AV_SAMPLE_FMT_S64,
    AV_SAMPLE_FMT_S64P,
    AV_SAMPLE_FMT_NB
};

enum __attribute__((deprecated)) AVMixCoeffType {
    AV_MIX_COEFF_TYPE_Q8,
    AV_MIX_COEFF_TYPE_Q15,
    AV_MIX_COEFF_TYPE_FLT,
    AV_MIX_COEFF_TYPE_NB
};

enum __attribute__((deprecated)) AVResampleFilterType {
    AV_RESAMPLE_FILTER_TYPE_CUBIC,
    AV_RESAMPLE_FILTER_TYPE_BLACKMAN_NUTTALL,
    AV_RESAMPLE_FILTER_TYPE_KAISER
};

enum __attribute__((deprecated)) AVResampleDitherMethod {
    AV_RESAMPLE_DITHER_NONE,
    AV_RESAMPLE_DITHER_RECTANGULAR,
    AV_RESAMPLE_DITHER_TRIANGULAR,
    AV_RESAMPLE_DITHER_TRIANGULAR_HP,
    AV_RESAMPLE_DITHER_TRIANGULAR_NS,
    AV_RESAMPLE_DITHER_NB
};

enum AVMatrixEncoding {
    AV_MATRIX_ENCODING_NONE,
    AV_MATRIX_ENCODING_DOLBY,
    AV_MATRIX_ENCODING_DPLII,
    AV_MATRIX_ENCODING_DPLIIX,
    AV_MATRIX_ENCODING_DPLIIZ,
    AV_MATRIX_ENCODING_DOLBYEX,
    AV_MATRIX_ENCODING_DOLBYHEADPHONE,
    AV_MATRIX_ENCODING_NB
};

enum RemapPoint {
    REMAP_NONE,
    REMAP_IN_COPY,
    REMAP_IN_CONVERT,
    REMAP_OUT_COPY,
    REMAP_OUT_CONVERT
};

typedef struct ChannelMapInfo {
    int channel_map[32];
    int do_remap;
    int channel_copy[32];
    int do_copy;
    int channel_zero[32];
    int do_zero;
    int input_map[32];
} ChannelMapInfo;

struct AudioData {
    const AVClass *class;
    uint8_t *data[32];
    uint8_t *buffer;
    unsigned int buffer_size;
    int allocated_samples;
    int nb_samples;
    enum AVSampleFormat sample_fmt;
    int channels;
    int allocated_channels;
    int is_planar;
    int planes;
    int sample_size;
    int stride;
    int read_only;
    int allow_realloc;
    int ptr_align;
    int samples_align;
    const char *name;
};

typedef struct AudioData AudioData;

typedef struct AVAudioFifo AVAudioFifo;
typedef struct AudioConvert AudioConvert;
typedef struct ResampleContext ResampleContext;
typedef struct AudioMix AudioMix;
typedef struct AVAudioResampleContext AVAudioResampleContext;

void (mix_func)(uint8_t **, void **, int, int, int);

struct AudioMix {
    AVAudioResampleContext *avr;
    enum AVSampleFormat fmt;
    enum AVMixCoeffType coeff_type;
    uint64_t in_layout;
    uint64_t out_layout;
    int in_channels;
    int out_channels;
    int ptr_align;
    int samples_align;
    int has_optimized_func;
    const char *func_descr;
    const char *func_descr_generic;
    void *mix;
    void *mix_generic;
    int in_matrix_channels;
    int out_matrix_channels;
    int output_zero[32];
    int input_skip[32];
    int output_skip[32];
    int16_t *matrix_q8[32];
    int32_t *matrix_q15[32];
    float *matrix_flt[32];
    void **matrix;
};

AudioMix *am;
double *matrix;
int stride;
int i;
int o;
int i0;
int o0;

void init_vars() {
    am = (AudioMix *)calloc(1, sizeof(AudioMix));
    if (!am) return;

    am->in_channels = 32;
    am->out_channels = 32;
    stride = 32;

    matrix = (double *)calloc(stride * am->out_channels, sizeof(double));
    if (!matrix) {
        free(am);
        return;
    }

    for (int ch = 0; ch < 32; ch++) {
        am->input_skip[ch] = (ch % 7 == 0) ? 1 : 0;
        am->output_zero[ch] = (ch % 5 == 0) ? 1 : 0;
    }

    o0 = 0;
    for (int o_idx = 0; o_idx < am->out_channels; o_idx++) {
        if (!am->output_zero[o_idx]) {
            am->matrix_q8[o0] = (int16_t *)calloc(am->in_channels, sizeof(int16_t));
            if (!am->matrix_q8[o0]) continue;
            for (int i_idx = 0; i_idx < am->in_channels; i_idx++) {
                am->matrix_q8[o0][i_idx] = (int16_t)(i_idx + o_idx + 1);
            }
            o0++;
        }
    }
}