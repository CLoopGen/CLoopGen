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
PullupFrame *fr;
int i;
int n;

static AVClass av_class_instance;
static PullupField field_list[50];
static uint8_t large_data_pool[16777216]; // ~16MB for pixel planes
static size_t data_offset = 0;

static uint8_t* allocate_plane(int width, int height) {
    size_t size = (size_t)width * height;
    if (data_offset + size > sizeof(large_data_pool)) {
        data_offset = 0; // wrap around if needed
    }
    uint8_t* ptr = &large_data_pool[data_offset];
    data_offset += size;
    return ptr;
}

void init_vars() {
    n = 4;

    s = (PullupContext*)calloc(1, sizeof(PullupContext));
    fr = (PullupFrame*)calloc(1, sizeof(PullupFrame));

    s->class = &av_class_instance;
    s->nb_planes = 3;
    s->planewidth[0] = 1920;
    s->planewidth[1] = 960;
    s->planewidth[2] = 960;
    s->planeheight[0] = 1080;
    s->planeheight[1] = 540;
    s->planeheight[2] = 540;

    for (int p = 0; p < 10; p++) {
        for (int i = 0; i < 3; i++) {
            s->buffers[p].planes[i] = allocate_plane(s->planewidth[i], s->planeheight[i]);
        }
        s->buffers[p].lock[0] = 0;
        s->buffers[p].lock[1] = 0;
    }

    for (int i = 0; i < 50; i++) {
        field_list[i].parity = i % 2;
        field_list[i].buffer = &s->buffers[i % 10];
        field_list[i].flags = 0;
        field_list[i].breaks = 0;
        field_list[i].affinity = 0;
        field_list[i].diffs = (int*)calloc(1920, sizeof(int));
        field_list[i].combs = (int*)calloc(1920, sizeof(int));
        field_list[i].vars = (int*)calloc(1920, sizeof(int));
    }

    for (int i = 0; i < 49; i++) {
        field_list[i].next = &field_list[i+1];
        field_list[i+1].prev = &field_list[i];
    }

    s->first = &field_list[0];
    s->last = &field_list[49];
    s->head = s->first;

    fr->length = 4;
    fr->parity = 0;
    fr->lock = 0;
    fr->buffer = NULL;

    for (int i = 0; i < 4; i++) {
        fr->ifields[i] = NULL;
        fr->ofields[i < 2 ? i : 0] = NULL;
    }

    s->diff = NULL;
    s->comb = NULL;
    s->var = NULL;
}