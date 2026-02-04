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

typedef struct QPContext {
    const AVClass *class;
    char *qp_expr_str;
    int8_t lut[257];
    int h;
    int qstride;
    int evaluate_per_mb;
} QPContext;

typedef struct AVBuffer {
    // dummy placeholder
    int dummy;
} AVBuffer;

typedef struct AVBufferRef {
    AVBuffer *buffer;
    uint8_t *data;
    int size;
} AVBufferRef;

QPContext *s;
AVBufferRef *out_qp_table_buf;
int y;
int x;
int qp;

static AVClass av_class_instance;
static uint8_t out_qp_table_data[16777216]; // ~16MB to target ~0.01 sec runtime

void init_vars() {
    s = (QPContext *)calloc(1, sizeof(QPContext));
    out_qp_table_buf = (AVBufferRef *)calloc(1, sizeof(AVBufferRef));
    out_qp_table_buf->buffer = (AVBuffer *)calloc(1, sizeof(AVBuffer));
    out_qp_table_buf->data = out_qp_table_data;
    out_qp_table_buf->size = sizeof(out_qp_table_data);

    s->h = 2048;
    s->qstride = 8192;
    s->evaluate_per_mb = 1;
    s->qp_expr_str = NULL;

    s->class = &av_class_instance;
    av_class_instance.class_name = "qp_context";
    av_class_instance.category = AV_CLASS_CATEGORY_FILTER;
    av_class_instance.item_name = NULL;
    av_class_instance.option = NULL;
    av_class_instance.version = 0;
    av_class_instance.log_level_offset_offset = 0;
    av_class_instance.parent_log_context_offset = 0;
    av_class_instance.child_next = NULL;
    av_class_instance.child_class_next = NULL;
    av_class_instance.get_category = NULL;
    av_class_instance.query_ranges = NULL;

    qp = 128;
}