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

typedef struct CodeItem {
    uint8_t bit;
    int size;
} CodeItem;

typedef struct LineItem {
    int input;
    int output;
    float unfiltered;
    float filtered;
    float average;
    float deviation;
} LineItem;

typedef struct ReadEIA608Context {
    const AVClass *class;
    int start;
    int end;
    int nb_found;
    int white;
    int black;
    float spw;
    int chp;
    int lp;
    uint64_t histogram[256];
    CodeItem *code;
    LineItem *line;
} ReadEIA608Context;

ReadEIA608Context *s;
int end;

void init_vars() {
    static AVClass av_class = {
        .class_name = "readeia608",
        .category = AV_CLASS_CATEGORY_FILTER
    };

    static uint64_t hist_data[256] = {0};
    static CodeItem code_data[1024];
    static LineItem line_data[2048];

    for (int i = 0; i < 1024; i++) {
        code_data[i].bit = i % 256;
        code_data[i].size = i * 3;
    }

    for (int i = 0; i < 2048; i++) {
        line_data[i].input = i;
        line_data[i].output = i * 2;
        line_data[i].unfiltered = i * 0.1f;
        line_data[i].filtered = i * 0.2f;
        line_data[i].average = i * 0.15f;
        line_data[i].deviation = i * 0.05f;
    }

    hist_data[254] = 1;

    static ReadEIA608Context ctx = {
        .class = &av_class,
        .start = 0,
        .end = 0,
        .nb_found = 0,
        .white = 128,
        .black = 32,
        .spw = 1.5f,
        .chp = 1,
        .lp = 0,
        .histogram = {0},
        .code = code_data,
        .line = line_data
    };

    for (int i = 0; i < 256; i++) {
        ctx.histogram[i] = hist_data[i];
    }

    s = &ctx;
    end = 0;
}