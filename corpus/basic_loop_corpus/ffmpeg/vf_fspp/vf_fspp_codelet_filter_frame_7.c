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

typedef struct FSPPContext {
    AVClass *class;
    uint64_t threshold_mtx_noq[16];
    uint64_t threshold_mtx[16];
    int log2_count;
    int strength;
    int hsub;
    int vsub;
    int temp_stride;
    int qp;
    int qscale_type;
    int prev_q;
    uint8_t *src;
    int16_t *temp;
    uint8_t *non_b_qp_table;
    int non_b_qp_alloc_size;
    int use_bframe_qp;
    void (*store_slice)(uint8_t *, int16_t *, ptrdiff_t, ptrdiff_t, ptrdiff_t, ptrdiff_t, ptrdiff_t);
    void (*store_slice2)(uint8_t *, int16_t *, ptrdiff_t, ptrdiff_t, ptrdiff_t, ptrdiff_t, ptrdiff_t);
    void (*mul_thrmat)(int16_t *, int16_t *, int);
    void (*column_fidct)(int16_t *, int16_t *, int16_t *, int);
    void (*row_idct)(int16_t *, int16_t *, ptrdiff_t, int);
    void (*row_fdct)(int16_t *, const uint8_t *, ptrdiff_t, int);
} FSPPContext;

extern FSPPContext *fspp;
extern int i;
extern int custom_threshold_m[64];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 8; i++) {
    fspp->threshold_mtx_noq[2 * i] = (uint64_t)custom_threshold_m[i * 8 + 2] | (((uint64_t)custom_threshold_m[i * 8 + 6]) << 16) | (((uint64_t)custom_threshold_m[i * 8 + 0]) << 32) | (((uint64_t)custom_threshold_m[i * 8 + 4]) << 48);
    fspp->threshold_mtx_noq[2 * i + 1] = (uint64_t)custom_threshold_m[i * 8 + 5] | (((uint64_t)custom_threshold_m[i * 8 + 3]) << 16) | (((uint64_t)custom_threshold_m[i * 8 + 1]) << 32) | (((uint64_t)custom_threshold_m[i * 8 + 7]) << 48);
}

}
