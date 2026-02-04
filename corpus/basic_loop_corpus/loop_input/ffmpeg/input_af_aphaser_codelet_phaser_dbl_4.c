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

typedef struct AVOption {
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
} AVOption;

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

struct AVOptionRanges;

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

typedef struct AudioPhaserContext {
    const AVClass *class;
    double in_gain;
    double out_gain;
    double delay;
    double decay;
    double speed;
    int type;
    int delay_buffer_length;
    double *delay_buffer;
    int modulation_buffer_length;
    int32_t *modulation_buffer;
    int delay_pos;
    int modulation_pos;
    void (*phaser)(struct AudioPhaserContext *, uint8_t *const *, uint8_t **, int, int);
} AudioPhaserContext;

AudioPhaserContext *s;
int nb_samples;
int channels;
int i;
int c;
int delay_pos;
int modulation_pos;
double *src;
double *dst;
double *buffer;

static AVClass global_avclass;
static AVOption global_options[2];

void init_vars() {
    channels = 2;
    nb_samples = 1 << 20;

    s = (AudioPhaserContext *)calloc(1, sizeof(AudioPhaserContext));
    if (!s) exit(1);

    s->in_gain = 0.8;
    s->out_gain = 0.9;
    s->decay = 0.7;
    s->delay_buffer_length = 1 << 16;
    s->modulation_buffer_length = 1 << 12;

    s->delay_buffer = (double *)calloc(s->delay_buffer_length * channels, sizeof(double));
    s->modulation_buffer = (int32_t *)calloc(s->modulation_buffer_length, sizeof(int32_t));
    if (!s->delay_buffer || !s->modulation_buffer) exit(1);

    for (int i = 0; i < s->modulation_buffer_length; i++) {
        s->modulation_buffer[i] = (i % (s->delay_buffer_length / 2)) + 1;
    }

    buffer = (double *)calloc(s->delay_buffer_length * channels, sizeof(double));
    if (!buffer) exit(1);

    src = (double *)calloc(nb_samples * channels, sizeof(double));
    dst = (double *)calloc(nb_samples * channels, sizeof(double));
    if (!src || !dst) exit(1);

    for (int i = 0; i < nb_samples * channels; i++) {
        src[i] = (double)(i % 1000) / 1000.0;
    }

    s->class = &global_avclass;
    s->delay_pos = 0;
    s->modulation_pos = 0;

    delay_pos = 0;
    modulation_pos = 0;
}