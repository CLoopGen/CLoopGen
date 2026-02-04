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
    const struct AVClass *class;
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

static const struct AVClass av_class = {0};

ReadEIA608Context *s;
int start;

static const char* dummy_item_name(void *ctx) { return "dummy"; }
static void* dummy_child_next(void *obj, void *prev) { return NULL; }
static const struct AVClass* dummy_child_class_next(const struct AVClass *prev) { return NULL; }
static int dummy_query_ranges(struct AVOptionRanges **ranges, void *obj, const char *key, int flags) { return 0; }

void init_vars() {
    s = (ReadEIA608Context*)calloc(1, sizeof(ReadEIA608Context));
    if (!s) exit(1);

    s->class = &av_class;
    s->start = 0;
    s->end = 0;
    s->nb_found = 0;
    s->white = 0;
    s->black = 0;
    s->spw = 0.0f;
    s->chp = 0;
    s->lp = 0;

    for (int i = 0; i < 256; i++) {
        s->histogram[i] = 0;
    }
    s->histogram[128] = 1;

    s->code = (CodeItem*)calloc(1, sizeof(CodeItem));
    if (!s->code) exit(1);
    s->code->bit = 0;
    s->code->size = 0;

    s->line = (LineItem*)calloc(1, sizeof(LineItem));
    if (!s->line) exit(1);
    s->line->input = 0;
    s->line->output = 0;
    s->line->unfiltered = 0.0f;
    s->line->filtered = 0.0f;
    s->line->average = 0.0f;
    s->line->deviation = 0.0f;

    start = 0;
}