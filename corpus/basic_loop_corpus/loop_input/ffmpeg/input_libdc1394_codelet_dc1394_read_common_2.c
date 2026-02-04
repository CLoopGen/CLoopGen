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

typedef struct AVOption {
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

struct AVOptionRanges {
    const struct AVOption *def;
    int nb_ranges;
    int nb_components;
};

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

struct dc1394_frame_rate {
    int frame_rate;
    int frame_rate_id;
};

typedef struct dc1394_data {
    AVClass *class;
    int *d;
    int *camera;
    int *frame;
    int current_frame;
    int frame_rate;
    char *video_size;
    char *pixel_format;
    char *framerate;
    int size;
    int stream_index;
} dc1394_data;

struct dc1394_frame_rate dc1394_frame_rates[512];
dc1394_data *dc1394;
struct dc1394_frame_rate *fps;

void init_vars() {
    for (int i = 0; i < 511; i++) {
        dc1394_frame_rates[i].frame_rate = (i + 1) * 10;
        dc1394_frame_rates[i].frame_rate_id = i;
    }
    dc1394_frame_rates[511].frame_rate = 0;
    dc1394_frame_rates[511].frame_rate_id = 0;

    dc1394 = (dc1394_data*)calloc(1, sizeof(dc1394_data));
    dc1394->frame_rate = 500;
    dc1394->class = NULL;
    dc1394->d = NULL;
    dc1394->camera = NULL;
    dc1394->frame = NULL;
    dc1394->current_frame = 0;
    dc1394->video_size = NULL;
    dc1394->pixel_format = NULL;
    dc1394->framerate = NULL;
    dc1394->size = 0;
    dc1394->stream_index = 0;

    fps = dc1394_frame_rates;
}