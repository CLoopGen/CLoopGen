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

typedef struct ChanDelay {
    int delay;
    unsigned int delay_index;
    unsigned int index;
    uint8_t *samples;
} ChanDelay;

typedef struct AudioDelayContext {
    const AVClass *class;
    int all;
    char *delays;
    ChanDelay *chandelay;
    int nb_delays;
    int block_align;
    int64_t padding;
    int64_t max_delay;
    int64_t next_pts;
    int eof;
    void (*delay_channel)(ChanDelay *, int, const uint8_t *, uint8_t *);
} AudioDelayContext;

static AVClass av_class_instance = {
    .class_name = "audio_delay",
    .category = AV_CLASS_CATEGORY_FILTER
};

static ChanDelay *generated_chandelay = NULL;
static uint8_t **generated_samples_pool = NULL;

AudioDelayContext *s;
int i;

void init_vars() {
    const int target_data_size = 64 * 1024 * 1024; // ~64MB total data
    const size_t avg_delay_per_channel = 8192;
    const int estimated_nb_delays = target_data_size / avg_delay_per_channel;
    s = (AudioDelayContext *)calloc(1, sizeof(AudioDelayContext));
    generated_chandelay = (ChanDelay *)calloc(estimated_nb_delays, sizeof(ChanDelay));
    generated_samples_pool = (uint8_t **)calloc(estimated_nb_delays, sizeof(uint8_t *));

    for (int idx = 0; idx < estimated_nb_delays; idx++) {
        size_t delay_size = avg_delay_per_channel + (idx % 4096);
        uint8_t *buf = (uint8_t *)calloc(delay_size, sizeof(uint8_t));
        generated_samples_pool[idx] = buf;
        generated_chandelay[idx].delay = delay_size;
        generated_chandelay[idx].delay_index = idx % 1024;
        generated_chandelay[idx].index = idx % 512;
        generated_chandelay[idx].samples = buf;
    }

    s->class = &av_class_instance;
    s->all = 0;
    s->delays = NULL;
    s->chandelay = generated_chandelay;
    s->nb_delays = estimated_nb_delays;
    s->block_align = 1;
    s->padding = 1024;
    s->max_delay = 0;
    s->next_pts = 0;
    s->eof = 0;
    s->delay_channel = NULL;
}