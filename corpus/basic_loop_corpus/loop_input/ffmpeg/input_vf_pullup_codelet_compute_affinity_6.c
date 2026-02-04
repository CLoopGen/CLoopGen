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

typedef struct PullupBuffer {
    int lock[2];
    uint8_t *planes[4];
} PullupBuffer;

typedef struct PullupField {
    int parity;
    PullupBuffer *buffer;
    unsigned int flags;
    int breaks;
    int affinity;
    int *diffs;
    int *combs;
    int *vars;
    struct PullupField *prev;
    struct PullupField *next;
} PullupField;

typedef struct PullupFrame {
    int lock;
    int length;
    int parity;
    PullupBuffer *ifields[4];
    PullupBuffer *ofields[2];
    PullupBuffer *buffer;
} PullupFrame;

typedef struct PullupContext {
    const AVClass *class;
    int junk_left;
    int junk_right;
    int junk_top;
    int junk_bottom;
    int metric_plane;
    int strict_breaks;
    int strict_pairs;
    int metric_w;
    int metric_h;
    int metric_length;
    int metric_offset;
    int nb_planes;
    int planewidth[4];
    int planeheight[4];
    PullupField *first;
    PullupField *last;
    PullupField *head;
    PullupBuffer buffers[10];
    PullupFrame frame;
    int (*diff)(const uint8_t *, const uint8_t *, ptrdiff_t);
    int (*comb)(const uint8_t *, const uint8_t *, ptrdiff_t);
    int (*var)(const uint8_t *, const uint8_t *, ptrdiff_t);
} PullupContext;

PullupContext *s;
PullupField *f;
int i;
int max_l;
int max_r;
int l;

static AVClass av_class_instance;
static PullupField prev_field;
static PullupField next_field;
static int *alloc_vars;
static int *alloc_combs;
static int *alloc_prev_combs;
static int *alloc_prev_vars;
static int *alloc_next_combs;
static int *alloc_next_vars;

void init_vars() {
    const int approx_metric_length = 50000000; // Adjust to achieve ~0.01 sec runtime

    alloc_vars = (int*)calloc(approx_metric_length, sizeof(int));
    alloc_combs = (int*)calloc(approx_metric_length, sizeof(int));
    alloc_prev_vars = (int*)calloc(approx_metric_length, sizeof(int));
    alloc_prev_combs = (int*)calloc(approx_metric_length, sizeof(int));
    alloc_next_vars = (int*)calloc(approx_metric_length, sizeof(int));
    alloc_next_combs = (int*)calloc(approx_metric_length, sizeof(int));

    for (int idx = 0; idx < approx_metric_length; idx++) {
        alloc_vars[idx] = rand() % 1000;
        alloc_combs[idx] = rand() % 2000 + 1000;
        alloc_prev_vars[idx] = rand() % 1000;
        alloc_prev_combs[idx] = rand() % 2000 + 1000;
        alloc_next_vars[idx] = rand() % 1000;
        alloc_next_combs[idx] = rand() % 2000 + 1000;
    }

    s = (PullupContext*)calloc(1, sizeof(PullupContext));
    f = (PullupField*)calloc(1, sizeof(PullupField));

    s->metric_length = approx_metric_length;

    f->vars = alloc_vars;
    f->combs = alloc_combs;

    f->prev = &prev_field;
    f->next = &next_field;

    prev_field.vars = alloc_prev_vars;
    prev_field.combs = alloc_prev_combs;

    next_field.vars = alloc_next_vars;
    next_field.combs = alloc_next_combs;

    max_l = 0;
    max_r = 0;
    l = 0;
}