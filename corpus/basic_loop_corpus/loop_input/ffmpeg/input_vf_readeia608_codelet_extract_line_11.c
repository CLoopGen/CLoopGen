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
int i;
int ch;
uint8_t byte[2];
uint8_t codes[19];
int parity;

static AVClass av_class_instance;
static CodeItem *code_items;
static LineItem *line_items;

void init_vars() {
    s = (ReadEIA608Context *)calloc(1, sizeof(ReadEIA608Context));
    if (!s) return;

    s->class = &av_class_instance;
    s->chp = 1;
    s->start = 0;
    s->end = 0;
    s->nb_found = 0;
    s->white = 0;
    s->black = 0;
    s->spw = 0.0f;
    s->lp = 0;
    for (int j = 0; j < 256; j++) {
        s->histogram[j] = 0;
    }

    code_items = (CodeItem *)calloc(32, sizeof(CodeItem));
    if (code_items) {
        for (int j = 0; j < 32; j++) {
            code_items[j].bit = j % 2;
            code_items[j].size = j;
        }
    }
    s->code = code_items;

    line_items = (LineItem *)calloc(1024, sizeof(LineItem));
    if (line_items) {
        for (int j = 0; j < 1024; j++) {
            line_items[j].input = j;
            line_items[j].output = j + 1;
            line_items[j].unfiltered = j * 1.1f;
            line_items[j].filtered = j * 1.2f;
            line_items[j].average = j * 0.5f;
            line_items[j].deviation = j * 0.1f;
        }
    }
    s->line = line_items;

    for (int j = 0; j < 19; j++) {
        codes[j] = (j < 3) ? 0 : ((j - 3) % 7 == 0) ? 255 : (j % 3);
    }

    byte[0] = 0;
    byte[1] = 0;
    i = 0;
    ch = 0;
    parity = 0;
}