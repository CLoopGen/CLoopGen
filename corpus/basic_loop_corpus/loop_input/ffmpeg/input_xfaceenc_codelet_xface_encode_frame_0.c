#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

typedef struct AVOption {} AVOption;

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

typedef struct XFaceContext {
    AVClass *class;
    uint8_t bitmap[2304];
    int max_line_len;
    int set_header;
} XFaceContext;

static AVClass av_class_instance;
static XFaceContext xface_instance;
static uint8_t *buf_ptr;

XFaceContext *xface = &xface_instance;
int i = 0;
int j = 0;
int k = 0;
uint8_t *buf = NULL;

void init_vars() {
    buf = (uint8_t*)malloc(16777216); // ~16MB to target ~0.01s runtime
    if (!buf) exit(1);

    for (size_t idx = 0; idx < 16777216; ++idx) {
        buf[idx] = rand() & 0xFF;
    }

    xface->class = &av_class_instance;
    xface->max_line_len = 2304;
    xface->set_header = 0;

    i = 0;
    j = 0;

    buf_ptr = buf;
}