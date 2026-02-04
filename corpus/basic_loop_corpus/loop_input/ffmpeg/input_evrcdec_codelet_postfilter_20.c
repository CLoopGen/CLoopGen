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
    AVClass *class;
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

struct PfCoeff {
    float tilt;
    float ltgain;
    float p1;
    float p2;
};

EVRCContext *e;
struct PfCoeff *pfc;
int length;
float temp[54];
float gamma;
int i;
int best;

void init_vars() {
    e = (EVRCContext *)calloc(1, sizeof(EVRCContext));
    pfc = (struct PfCoeff *)calloc(1, sizeof(struct PfCoeff));
    
    // Set data size so that loop runs ~0.01 seconds: ~10 million iterations typical
    length = 54;  // Fixed by array declaration of temp[54]
    best = 10;
    gamma = 0.85f;

    // Ensure no out-of-bounds access: temp[i] and postfilter_residual[128+i], [128+i-best]
    // i from 0 to 53 => indices 128 to 181 and 118 to 171 -> within 182 elements
    for (int j = 0; j < 182; j++) {
        e->postfilter_residual[j] = (float)(j % 100) / 100.0f;
    }

    pfc->ltgain = 0.9f;

    for (int j = 0; j < 10; j++) {
        e->lspf[j] = 0.1f * j;
        e->prev_lspf[j] = 0.1f * j;
        e->synthesis[j] = 0.0f;
        e->postfilter_fir[j] = 0.1f;
        e->postfilter_iir[j] = 0.1f;
    }

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
        e->energy_vector[j] = 0.5f;
    }

    e->fade_scale = 1.0f;
    e->last = 0.0f;
    e->prev_energy_gain = 0;
    e->prev_error_flag = 0;
    e->warned_buf_mismatch_bitrate = 0;

    e->postfilter = 1;
    e->bitrate = RATE_FULL;
    e->last_valid_bitrate = RATE_FULL;

    e->frame.lpc_flag = 0;
    e->frame.pitch_delay = 20;
    e->frame.delay_diff = 5;
    e->frame.acb_gain[0] = 10;
    e->frame.acb_gain[1] = 15;
    e->frame.acb_gain[2] = 20;
    e->frame.fcb_gain[0] = 5;
    e->frame.fcb_gain[1] = 8;
    e->frame.fcb_gain[2] = 12;
    e->frame.energy_gain = 30;
    e->frame.tty = 0;

    for (int j = 0; j < 4; j++) {
        e->frame.lsp[j] = 1000 + j * 100;
        for (int k = 0; k < 3; k++) {
            e->frame.fcb_shape[k][j] = 50 + j * 10 + k;
        }
    }

    pfc->tilt = 0.7f;
    pfc->p1 = 0.3f;
    pfc->p2 = 0.4f;

    for (int j = 0; j < 54; j++) {
        temp[j] = 0.0f;
    }
}