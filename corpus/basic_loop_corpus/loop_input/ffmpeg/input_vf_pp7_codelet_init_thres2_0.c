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

typedef struct AVOptionRanges {
    int length;
} AVOptionRanges;

typedef struct PP7Context {
    struct AVClass *class;
    int thres2[99][16];
    int qp;
    int mode;
    int qscale_type;
    int hsub;
    int vsub;
    int temp_stride;
    uint8_t *src;
    int (*requantize)(struct PP7Context *, int16_t *, int);
    void (*dctB)(int16_t *, int16_t *);
} PP7Context;

PP7Context *p;
int qp;
int i;
int bias;

void init_vars() {
    p = (PP7Context *)calloc(1, sizeof(PP7Context));
    if (!p) exit(1);

    p->class = (struct AVClass *)calloc(1, sizeof(struct AVClass));
    if (!p->class) exit(1);

    p->class->class_name = "pp7";
    p->class->category = AV_CLASS_CATEGORY_FILTER;
    p->class->version = 1;

    p->qp = 0;
    p->mode = 0;
    p->qscale_type = 0;
    p->hsub = 1;
    p->vsub = 1;
    p->temp_stride = 16;
    p->src = (uint8_t *)calloc(1, 1024 * 1024); // ~1MB buffer
    if (!p->src) exit(1);

    p->requantize = NULL;
    p->dctB = NULL;

    bias = 5;
}