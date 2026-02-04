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

typedef struct DejudderContext {
    const AVClass *class;
    int64_t *ringbuff;
    int i1;
    int i2;
    int i3;
    int i4;
    int64_t new_pts;
    int start_count;
    int cycle;
} DejudderContext;

extern int k;
extern DejudderContext *s;
extern int64_t *judbuff;
extern int64_t offset;

static struct AVClass av_class_instance = {
    .class_name = "dejudder",
    .category = AV_CLASS_CATEGORY_FILTER
};

static struct AVOption option_instance = {
    .name = "example_option",
    .type = AV_OPT_TYPE_INT,
    .default_val.i64 = 0,
    .min = 0,
    .max = 100,
    .flags = 0
};

static const struct AVOption *options = &option_instance;

static int64_t *ring_buffer = NULL;
static int64_t *jitter_buffer = NULL;

DejudderContext *s;
int64_t *judbuff;
int k = 0;
int64_t offset = 1000;

void init_vars(void) {
    const int approx_data_size = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec on modern CPU
    const int element_size = sizeof(int64_t);
    const int num_elements = approx_data_size / element_size;

    ring_buffer = calloc(num_elements + 2, sizeof(int64_t));
    jitter_buffer = calloc(num_elements + 2, sizeof(int64_t));
    if (!ring_buffer || !jitter_buffer) {
        exit(1);
    }

    s = malloc(sizeof(DejudderContext));
    if (!s) {
        exit(1);
    }

    s->class = &av_class_instance;
    s->ringbuff = ring_buffer;
    s->cycle = num_elements;
    s->i1 = s->i2 = s->i3 = s->i4 = 0;
    s->new_pts = 0;
    s->start_count = 0;

    judbuff = jitter_buffer;
    offset = 1000;

    for (int i = 0; i < s->cycle + 2; i++) {
        judbuff[i] = i * 100;
    }
}