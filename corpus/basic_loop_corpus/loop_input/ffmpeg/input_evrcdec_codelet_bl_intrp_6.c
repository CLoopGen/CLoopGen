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
} OptionDefaultVal;

struct AVOption {
    const char *name;
    const char *help;
    int offset;
    enum AVOptionType type;
    OptionDefaultVal default_val;
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

struct AVOptionRanges {
    int dummy;
};

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

EVRCContext *e;
float *ex;
float *f;
int i;
int coef_idx;

void init_vars() {
    e = (EVRCContext *)calloc(1, sizeof(EVRCContext));
    ex = (float *)calloc(1, sizeof(float));
    f = (float *)calloc(17, sizeof(float)); // Size 17 to cover 2*8+1 = 17 elements
    for (int j = 0; j < 17; j++) {
        f[j] = 1.0f;
    }
    coef_idx = 0; // Ensure coef_idx + i < 136 (size of interpolation_coeffs), with i up to 16

    // Initialize AVClass to avoid null pointer issues
    e->class = (AVClass *)calloc(1, sizeof(AVClass));
    e->class->class_name = "evrc";
    e->class->category = AV_CLASS_CATEGORY_DECODER;

    // Ensure interpolation_coeffs is initialized
    for (int j = 0; j < 136; j++) {
        e->interpolation_coeffs[j] = 1.0f / (j + 1);
    }

    // Allocate and initialize gb buffer to prevent UB
    e->gb.buffer = (const uint8_t *)calloc(1, 1024);
    e->gb.buffer_end = e->gb.buffer + 1024;
    e->gb.index = 0;
    e->gb.size_in_bits = 8192;
    e->gb.size_in_bits_plus8 = 8200;
}