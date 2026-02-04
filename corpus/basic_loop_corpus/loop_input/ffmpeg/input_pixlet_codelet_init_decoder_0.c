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

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

typedef struct GetBitContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    int index;
    int size_in_bits;
    int size_in_bits_plus8;
} GetBitContext;

typedef struct SubBand {
    unsigned int width;
    unsigned int height;
    unsigned int size;
    unsigned int x;
    unsigned int y;
} SubBand;

typedef struct PixletContext {
    AVClass *class;
    GetByteContext gb;
    GetBitContext bc;
    int levels;
    int depth;
    int w;
    int h;
    int16_t *filter[2];
    int16_t *prediction;
    int64_t scaling[4][2][4];
    SubBand band[4][13];
} PixletContext;

PixletContext *ctx;
int i;
int plane;

static AVClass av_class = {
    .class_name = "pixlet",
    .category = AV_CLASS_CATEGORY_DECODER,
};

static uint8_t dummy_buffer[1 << 20]; // 1MB buffer

static void init_gbc(GetBitContext *gbc) {
    gbc->buffer = dummy_buffer;
    gbc->buffer_end = dummy_buffer + sizeof(dummy_buffer);
    gbc->index = 0;
    gbc->size_in_bits = sizeof(dummy_buffer) * 8;
    gbc->size_in_bits_plus8 = gbc->size_in_bits + 8;
}

static void init_gbc_static(void) {
    static GetBitContext gbc;
    init_gbc(&gbc);
    ctx->bc = gbc;
}

void init_vars() {
    ctx = (PixletContext*)calloc(1, sizeof(PixletContext));
    if (!ctx) exit(1);

    ctx->class = &av_class;
    ctx->gb.buffer = dummy_buffer;
    ctx->gb.buffer_end = dummy_buffer + sizeof(dummy_buffer);
    ctx->gb.buffer_start = dummy_buffer;

    init_gbc(&ctx->bc);

    ctx->levels = 5;
    ctx->depth = 10;
    ctx->w = 1920;
    ctx->h = 1080;

    for (int f = 0; f < 2; f++) {
        ctx->filter[f] = (int16_t*)calloc(32, sizeof(int16_t));
        if (!ctx->filter[f]) exit(1);
    }

    ctx->prediction = (int16_t*)calloc(ctx->w * ctx->h, sizeof(int16_t));
    if (!ctx->prediction) exit(1);

    for (int a = 0; a < 4; a++)
        for (int b = 0; b < 2; b++)
            for (int c = 0; c < 4; c++)
                ctx->scaling[a][b][c] = (int64_t)(a * 100 + b * 10 + c);

    for (int p = 0; p < 4; p++)
        for (int b = 0; b < 13; b++) {
            ctx->band[p][b].width = 0;
            ctx->band[p][b].height = 0;
            ctx->band[p][b].size = 0;
            ctx->band[p][b].x = 0;
            ctx->band[p][b].y = 0;
        }
}