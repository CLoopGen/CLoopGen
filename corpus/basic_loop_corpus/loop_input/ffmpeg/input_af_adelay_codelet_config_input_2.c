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

typedef struct AVOptionRanges {
    void *dummy;
} AVOptionRanges;

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

AudioDelayContext *s;
int i;

void init_vars() {
    s = (AudioDelayContext *)calloc(1, sizeof(AudioDelayContext));
    if (!s) return;

    static AVClass avclass = {0};
    s->class = &avclass;
    s->all = 0;
    s->delays = NULL;
    s->block_align = 2;
    s->padding = 0;
    s->max_delay = 1000;
    s->next_pts = 0;
    s->eof = 0;
    s->delay_channel = NULL;

    s->nb_delays = 5000000; // ~100MB of ChanDelay data

    s->chandelay = (ChanDelay *)calloc(s->nb_delays, sizeof(ChanDelay));
    if (!s->chandelay) {
        free(s);
        s = NULL;
        return;
    }

    for (int idx = 0; idx < s->nb_delays; idx++) {
        s->chandelay[idx].delay = idx % 1000;
        s->chandelay[idx].delay_index = idx % 100;
        s->chandelay[idx].index = idx % 50;
        s->chandelay[idx].samples = (uint8_t *)calloc(1, 1); // dummy allocation
    }

    i = 1;
}

extern void loop(void);