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

typedef union {
    int64_t i64;
    double dbl;
    const char *str;
    AVRational q;
} DefaultValUnion;

struct AVOption {
    const char *name;
    const char *help;
    int offset;
    enum AVOptionType type;
    DefaultValUnion default_val;
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

struct AVClass {
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
};

typedef struct GetBitContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    int index;
    int size_in_bits;
    int size_in_bits_plus8;
} GetBitContext;

typedef enum {
    RATE_ERRS = -1,
    SILENCE,
    RATE_QUANT,
    RATE_QUARTER,
    RATE_HALF,
    RATE_FULL
} evrc_packet_rate;

typedef struct EVRCAFrame {
    uint8_t lpc_flag;
    uint16_t lsp[4];
    uint8_t pitch_delay;
    uint8_t delay_diff;
    uint8_t acb_gain[3];
    uint16_t fcb_shape[3][4];
    uint8_t fcb_gain[3];
    uint8_t energy_gain;
    uint8_t tty;
} EVRCAFrame;

typedef struct EVRCContext {
    struct AVClass *class;
    int postfilter;
    GetBitContext gb;
    evrc_packet_rate bitrate;
    evrc_packet_rate last_valid_bitrate;
    EVRCAFrame frame;
    float lspf[10];
    float prev_lspf[10];
    float synthesis[10];
    float postfilter_fir[10];
    float postfilter_iir[10];
    float postfilter_residual[182];
    float pitch_delay;
    float prev_pitch_delay;
    float avg_acb_gain;
    float avg_fcb_gain;
    float pitch[192];
    float pitch_back[128];
    float interpolation_coeffs[136];
    float energy_vector[3];
    float fade_scale;
    float last;
    uint8_t prev_energy_gain;
    uint8_t prev_error_flag;
    uint8_t warned_buf_mismatch_bitrate;
} EVRCContext;

#define DATA_SIZE (1 << 20)

static float in_data[DATA_SIZE];
static float scratch_data[54];
static EVRCContext e_context;

EVRCContext *e = &e_context;
float *in = in_data;
int length = 54;
float scratch[54];
float tilt = 0.5f;
int i;

void init_vars() {
    for (int j = 0; j < DATA_SIZE; j++) {
        in_data[j] = (float)(j % 100) / 100.0f;
    }
    for (int j = 0; j < 54; j++) {
        scratch_data[j] = 0.0f;
    }
    e->class = NULL;
    e->postfilter = 1;
    e->gb.buffer = NULL;
    e->gb.buffer_end = NULL;
    e->gb.index = 0;
    e->gb.size_in_bits = 0;
    e->gb.size_in_bits_plus8 = 0;
    e->bitrate = RATE_FULL;
    e->last_valid_bitrate = RATE_FULL;
    e->frame.lpc_flag = 0;
    e->frame.pitch_delay = 0;
    e->frame.delay_diff = 0;
    e->frame.energy_gain = 0;
    e->frame.tty = 0;
    for (int j = 0; j < 4; j++) {
        e->frame.lsp[j] = 0;
    }
    for (int j = 0; j < 3; j++) {
        e->frame.acb_gain[j] = 0;
        e->frame.fcb_gain[j] = 0;
        for (int k = 0; k < 4; k++) {
            e->frame.fcb_shape[j][k] = 0;
        }
    }
    for (int j = 0; j < 10; j++) {
        e->lspf[j] = 0.0f;
        e->prev_lspf[j] = 0.0f;
        e->synthesis[j] = 0.0f;
        e->postfilter_fir[j] = 0.0f;
        e->postfilter_iir[j] = 0.0f;
    }
    for (int j = 0; j < 182; j++) {
        e->postfilter_residual[j] = 0.0f;
    }
    e->pitch_delay = 0.0f;
    e->prev_pitch_delay = 0.0f;
    e->avg_acb_gain = 0.0f;
    e->avg_fcb_gain = 0.0f;
    for (int j = 0; j < 192; j++) {
        e->pitch[j] = 0.0f;
    }
    for (int j = 0; j < 128; j++) {
        e->pitch_back[j] = 0.0f;
    }
    for (int j = 0; j < 136; j++) {
        e->interpolation_coeffs[j] = 0.0f;
    }
    for (int j = 0; j < 3; j++) {
        e->energy_vector[j] = 0.0f;
    }
    e->fade_scale = 1.0f;
    e->last = 0.0f;
    e->prev_energy_gain = 0;
    e->prev_error_flag = 0;
    e->warned_buf_mismatch_bitrate = 0;
}