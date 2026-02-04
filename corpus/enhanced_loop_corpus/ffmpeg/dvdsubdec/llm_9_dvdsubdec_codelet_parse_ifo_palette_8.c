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

extern DVDSubContext *ctx;
extern uint8_t r;
extern uint8_t g;
extern uint8_t b;
extern uint8_t *buf;
extern int i;
extern int y;
extern int cb;
extern int cr;
extern int r_add;
extern int g_add;
extern int b_add;
extern  uint8_t *cm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i += 2) {
    int y1, y2, cr1, cr2, cb1, cb2;
    y1 = *++buf; cr1 = *++buf; cb1 = *++buf;
    y2 = *++buf; cr2 = *++buf; cb2 = *++buf;

    cb1 -= 128; cr1 -= 128;
    cb2 -= 128; cr2 -= 128;

    int r_add1 = (1638 * cr1 + 512) >> 10;
    int g_add1 = (-399 * cb1 - 827 * cr1 + 512) >> 10;
    int b_add1 = (2054 * cb1 + 512) >> 10;

    int r_add2 = (1638 * cr2 + 512) >> 10;
    int g_add2 = (-399 * cb2 - 827 * cr2 + 512) >> 10;
    int b_add2 = (2054 * cb2 + 512) >> 10;

    y1 = ((y1 - 16) * 1175) >> 10;
    y2 = ((y2 - 16) * 1175) >> 10;

    r = cm[(y1 + r_add1)]; g = cm[(y1 + g_add1)]; b = cm[(y1 + b_add1)];
    ctx->palette[i] = (r << 16) | (g << 8) | b;

    if (i + 1 < 16) {
        r = cm[(y2 + r_add2)]; g = cm[(y2 + g_add2)]; b = cm[(y2 + b_add2)];
        ctx->palette[i + 1] = (r << 16) | (g << 8) | b;
    }

    buf += 2;
}
}
