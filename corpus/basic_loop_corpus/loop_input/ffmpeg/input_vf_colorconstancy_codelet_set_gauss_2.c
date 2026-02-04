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
    const AVOption *option;
    int version;
    int log_level_offset_offset;
    int parent_log_context_offset;
    void *(*child_next)(void *, void *);
    const struct AVClass *(*child_class_next)(const struct AVClass *);
    AVClassCategory category;
    AVClassCategory (*get_category)(void *);
    int (*query_ranges)(struct AVOptionRanges **, void *, const char *, int);
} AVClass;

typedef struct ColorConstancyContext {
    const AVClass *class;
    int difford;
    int minknorm;
    double sigma;
    int nb_threads;
    int planeheight[4];
    int planewidth[4];
    int filtersize;
    double *gauss[3];
    double white[3];
} ColorConstancyContext;

ColorConstancyContext *s;
int filtersize;
double sum1;
double sum2;
int i;

void init_vars() {
    filtersize = 1 << 20; // ~1M elements to target ~0.01 sec runtime

    s = (ColorConstancyContext *)calloc(1, sizeof(ColorConstancyContext));
    if (!s) exit(1);

    s->filtersize = filtersize;

    for (int j = 0; j < 3; ++j) {
        s->gauss[j] = (double *)calloc(filtersize, sizeof(double));
        if (!s->gauss[j]) exit(1);
    }

    s->class = (AVClass *)calloc(1, sizeof(AVClass));
    if (!s->class) exit(1);

    ((AVClass *)(s->class))->class_name = "color_constancy";
    ((AVClass *)(s->class))->category = AV_CLASS_CATEGORY_FILTER;

    sum1 = 123456.789;
    sum2 = 0.0;

    for (int j = 0; j < filtersize; ++j) {
        s->gauss[2][j] = 1.0 + (double)j / filtersize;
    }
}