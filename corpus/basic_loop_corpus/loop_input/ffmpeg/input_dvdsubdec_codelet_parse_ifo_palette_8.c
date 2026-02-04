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

typedef struct DVDSubContext {
    AVClass *class;
    uint32_t palette[16];
    char *palette_str;
    char *ifo_str;
    int has_palette;
    uint8_t colormap[4];
    uint8_t alpha[256];
    uint8_t buf[65536];
    int buf_size;
    int forced_subs_only;
    uint8_t used_color[256];
} DVDSubContext;

DVDSubContext *ctx;
uint8_t r;
uint8_t g;
uint8_t b;
uint8_t *buf;
int i;
int y;
int cb;
int cr;
int r_add;
int g_add;
int b_add;
uint8_t *cm;

static uint8_t static_buf[65536];
static uint8_t static_cm[1024];
static AVClass static_avclass;
static DVDSubContext static_ctx;

void init_vars() {
    ctx = &static_ctx;
    buf = static_buf;
    cm = static_cm;

    ctx->class = &static_avclass;
    ctx->has_palette = 0;
    ctx->buf_size = 65536;
    ctx->forced_subs_only = 0;
    for (int j = 0; j < 16; j++) {
        ctx->palette[j] = 0;
    }
    for (int j = 0; j < 256; j++) {
        ctx->alpha[j] = 255;
        ctx->used_color[j] = 0;
    }
    for (int j = 0; j < 4; j++) {
        ctx->colormap[j] = j;
    }
    for (int j = 0; j < 65536; j++) {
        static_buf[j] = rand() % 256;
    }
    for (int j = 0; j < 1024; j++) {
        static_cm[j] = (j < 256) ? j : ((j >= 256 && j < 768) ? 128 : 255);
    }

    r = 0;
    g = 0;
    b = 0;
    i = 0;
    y = 0;
    cb = 0;
    cr = 0;
    r_add = 0;
    g_add = 0;
    b_add = 0;
}