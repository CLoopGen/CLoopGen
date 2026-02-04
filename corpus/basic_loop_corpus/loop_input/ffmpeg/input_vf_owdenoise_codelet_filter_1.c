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

typedef struct OWDenoiseContext {
    const AVClass *class;
    double luma_strength;
    double chroma_strength;
    int depth;
    float *plane[17][4];
    int linesize;
    int hsub;
    int vsub;
    int pixel_depth;
} OWDenoiseContext;

OWDenoiseContext *s;
uint8_t *src;
int src_linesize;
int width;
int height;
int x;
int y;

static AVClass av_class = {
    .class_name = "owdenoise",
    .category = AV_CLASS_CATEGORY_FILTER
};

void init_vars() {
    width = 1920;
    height = 1080;
    src_linesize = width;
    s = malloc(sizeof(OWDenoiseContext));
    s->class = &av_class;
    s->luma_strength = 0.5;
    s->chroma_strength = 0.3;
    s->depth = 8;
    s->linesize = width;
    s->hsub = 1;
    s->vsub = 1;
    s->pixel_depth = 8;

    src = malloc(src_linesize * height * sizeof(uint8_t));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            src[i * src_linesize + j] = rand() % 256;
        }
    }

    for (int p = 0; p < 17; p++) {
        for (int f = 0; f < 4; f++) {
            s->plane[p][f] = malloc(s->linesize * height * sizeof(float));
            for (int i = 0; i < s->linesize * height; i++) {
                s->plane[p][f][i] = 0.0f;
            }
        }
    }

    x = 0;
    y = 0;
}