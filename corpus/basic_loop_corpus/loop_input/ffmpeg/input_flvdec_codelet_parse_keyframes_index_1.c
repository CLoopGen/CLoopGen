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

struct {
    int64_t dts;
    int64_t pos;
};

typedef struct FLVContext {
    const AVClass *class;
    int trust_metadata;
    int trust_datasize;
    int dump_full_metadata;
    int wrong_dts;
    uint8_t *new_extradata[4];
    int new_extradata_size[4];
    int last_sample_rate;
    int last_channels;
    struct {
        int64_t dts;
        int64_t pos;
    } validate_index[2];
    int validate_next;
    int validate_count;
    int searched_for_end;
    uint8_t resync_buffer[2097152];
    int broken_sizes;
    int64_t sum_flv_tag_size;
    int last_keyframe_stream_index;
    int keyframe_count;
    int64_t video_bit_rate;
    int64_t audio_bit_rate;
    int64_t *keyframe_times;
    int64_t *keyframe_filepositions;
    int missing_streams;
    AVRational framerate;
    int64_t last_ts;
    int64_t time_offset;
    int64_t time_pos;
} FLVContext;

FLVContext *flv;
unsigned int fileposlen;
unsigned int i;
int64_t *times;
int64_t *filepositions;

void init_vars() {
    fileposlen = 256 * 1024 * 1024 / sizeof(int64_t); // ~2GB of data for ~0.01s runtime assumption

    times = malloc(fileposlen * sizeof(int64_t));
    filepositions = malloc(fileposlen * sizeof(int64_t));
    if (!times || !filepositions) {
        exit(1);
    }

    for (unsigned int idx = 0; idx < fileposlen; ++idx) {
        times[idx] = idx * 30;
        filepositions[idx] = idx * 1000;
    }

    flv = malloc(sizeof(FLVContext));
    if (!flv) {
        exit(1);
    }

    flv->class = NULL;
    flv->trust_metadata = 1;
    flv->trust_datasize = 1;
    flv->dump_full_metadata = 0;
    flv->wrong_dts = 0;
    for (int j = 0; j < 4; ++j) {
        flv->new_extradata[j] = NULL;
        flv->new_extradata_size[j] = 0;
    }
    flv->last_sample_rate = 44100;
    flv->last_channels = 2;
    flv->validate_next = 0;
    flv->validate_count = 0;
    flv->searched_for_end = 0;
    flv->broken_sizes = 0;
    flv->sum_flv_tag_size = 0;
    flv->last_keyframe_stream_index = -1;
    flv->keyframe_count = 0;
    flv->video_bit_rate = 1000000;
    flv->audio_bit_rate = 128000;
    flv->keyframe_times = NULL;
    flv->keyframe_filepositions = NULL;
    flv->missing_streams = 0;
    flv->framerate.num = 30;
    flv->framerate.den = 1;
    flv->last_ts = 0;
    flv->time_offset = 0;
    flv->time_pos = 0;
}