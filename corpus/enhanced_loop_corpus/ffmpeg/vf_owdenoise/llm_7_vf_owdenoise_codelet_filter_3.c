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

typedef struct OWDenoiseContext {
    const AVClass *class;
    double luma_strength;
    double chroma_strength;
    int depth;
    float *plane[17][4];
    int linesize;
    int hsub;
    int vsub;
    int pixel_depth;
} OWDenoiseContext;

extern __attribute__((aligned(8)))  uint8_t dither[8][8];
extern OWDenoiseContext *s;
extern uint8_t *dst;
extern int dst_linesize;
extern int width;
extern int height;
extern int x;
extern int y;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double inv_64 = 1.0 / 64.0;
    double inv_128 = 1.0 / 128.0;
    for (y = 0; y < height; y++) {
        int dy = y & 7;
        for (x = 0; x < width; x += 2) {
            int dx1 = x & 7, dx2 = (x+1) & 7;
            int idx1 = y * s->linesize + x;
            int idx2 = idx1 + 1;
            int dst_idx1 = y * dst_linesize + x;
            int dst_idx2 = dst_idx1 + 1;

            double val1 = s->plane[0][0][idx1] + dither[dx1][dy] * inv_64 + inv_128;
            double val2 = s->plane[0][0][idx2] + dither[dx2][dy] * inv_64 + inv_128;

            i = (int)val1;
            if ((unsigned)i > 255U) i = (i < 0) ? 0 : 255;
            dst[dst_idx1] = i;

            if (x + 1 < width) {
                i = (int)val2;
                if ((unsigned)i > 255U) i = (i < 0) ? 0 : 255;
                dst[dst_idx2] = i;
            }
        }
    }
}
