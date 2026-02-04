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

union {
    int64_t i64;
    double dbl;
    const char *str;
    AVRational q;
};

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

enum PrintFormat {
    NONE,
    JSON,
    SUMMARY,
    PF_NB
};

enum LimiterState {
    OUT,
    ATTACK,
    SUSTAIN,
    RELEASE,
    STATE_NB
};

enum FrameType {
    FIRST_FRAME,
    INNER_FRAME,
    FINAL_FRAME,
    LINEAR_MODE,
    FRAME_NB
};

typedef struct FFEBUR128StateInternal FFEBUR128StateInternal;

typedef struct FFEBUR128State {
    int mode;
    unsigned int channels;
    unsigned long samplerate;
    FFEBUR128StateInternal *d;
} FFEBUR128State;

typedef struct LoudNormContext {
    const AVClass *class;
    double target_i;
    double target_lra;
    double target_tp;
    double measured_i;
    double measured_lra;
    double measured_tp;
    double measured_thresh;
    double offset;
    int linear;
    int dual_mono;
    enum PrintFormat print_format;
    double *buf;
    int buf_size;
    int buf_index;
    int prev_buf_index;
    double delta[30];
    double weights[21];
    double prev_delta;
    int index;
    double gain_reduction[2];
    double *limiter_buf;
    double *prev_smp;
    int limiter_buf_index;
    int limiter_buf_size;
    enum LimiterState limiter_state;
    int peak_index;
    int env_index;
    int env_cnt;
    int attack_length;
    int release_length;
    int64_t pts;
    enum FrameType frame_type;
    int above_threshold;
    int prev_nb_samples;
    int channels;
    FFEBUR128State *r128_in;
    FFEBUR128State *r18_out;
} LoudNormContext;

LoudNormContext *s;
int channels = 8;
int n;
int c;
double *buf;

static double global_audio_buffer[1920 * 8];
static double limiter_buffer[4096];
static double prev_samples[8];
static FFEBUR128State r128_in_state;
static FFEBUR128State r128_out_state;
static AVClass loudnorm_class;

void init_vars() {
    s = (LoudNormContext *)calloc(1, sizeof(LoudNormContext));
    if (!s) return;

    s->class = &loudnorm_class;
    s->target_i = -23.0;
    s->target_lra = 7.0;
    s->target_tp = -2.0;
    s->measured_i = -20.0;
    s->measured_lra = 5.0;
    s->measured_tp = -1.0;
    s->measured_thresh = -40.0;
    s->offset = 1.0;
    s->linear = 0;
    s->dual_mono = 0;
    s->print_format = SUMMARY;
    s->buf = global_audio_buffer;
    s->buf_size = 1920 * 8;
    s->buf_index = 0;
    s->prev_buf_index = 0;
    for (int i = 0; i < 30; i++) s->delta[i] = 0.0;
    for (int i = 0; i < 21; i++) s->weights[i] = 1.0;
    s->prev_delta = 0.0;
    s->index = 0;
    s->gain_reduction[0] = 1.0;
    s->gain_reduction[1] = 0.95;
    s->limiter_buf = limiter_buffer;
    s->prev_smp = prev_samples;
    s->limiter_buf_index = 0;
    s->limiter_buf_size = 4096;
    s->limiter_state = OUT;
    s->peak_index = 0;
    s->env_index = 0;
    s->env_cnt = 0;
    s->attack_length = 512;
    s->release_length = 1024;
    s->pts = 0;
    s->frame_type = INNER_FRAME;
    s->above_threshold = 1;
    s->prev_nb_samples = 1920;
    s->channels = channels;
    s->r128_in = &r128_in_state;
    s->r18_out = &r128_out_state;

    for (int i = 0; i < 1920; i++) {
        for (int j = 0; j < channels; j++) {
            global_audio_buffer[i * channels + j] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        }
    }

    buf = global_audio_buffer;
}