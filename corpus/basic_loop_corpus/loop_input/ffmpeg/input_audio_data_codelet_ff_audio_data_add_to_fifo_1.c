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

enum AVSampleFormat {
    AV_SAMPLE_FMT_NONE = -1,
    AV_SAMPLE_FMT_U8,
    AV_SAMPLE_FMT_S16,
    AV_SAMPLE_FMT_S32,
    AV_SAMPLE_FMT_FLT,
    AV_SAMPLE_FMT_DBL,
    AV_SAMPLE_FMT_U8P,
    AV_SAMPLE_FMT_S16P,
    AV_SAMPLE_FMT_S32P,
    AV_SAMPLE_FMT_FLTP,
    AV_SAMPLE_FMT_DBLP,
    AV_SAMPLE_FMT_S64,
    AV_SAMPLE_FMT_S64P,
    AV_SAMPLE_FMT_NB
};

struct AudioData {
    const AVClass *class;
    uint8_t *data[32];
    uint8_t *buffer;
    unsigned int buffer_size;
    int allocated_samples;
    int nb_samples;
    enum AVSampleFormat sample_fmt;
    int channels;
    int allocated_channels;
    int is_planar;
    int planes;
    int sample_size;
    int stride;
    int read_only;
    int allow_realloc;
    int ptr_align;
    int samples_align;
    const char *name;
};

typedef struct AudioData AudioData;

AudioData *a;
uint8_t *offset_data[32];
int offset_size;
int p;

static AVClass av_class_instance = {
    .class_name = "test_audio_class",
    .category = AV_CLASS_CATEGORY_INPUT
};

void init_vars() {
    a = (AudioData *)malloc(sizeof(AudioData));
    if (!a) return;

    a->class = &av_class_instance;
    a->buffer_size = 16777216; // 16 MB
    a->buffer = (uint8_t *)malloc(a->buffer_size);
    if (!a->buffer) {
        free(a);
        return;
    }

    a->planes = 8;
    a->sample_size = 2;
    a->is_planar = 1;
    a->nb_samples = 2097152; // ~2M samples per plane
    a->allocated_samples = a->nb_samples;
    a->channels = 8;
    a->allocated_channels = a->channels;
    a->sample_fmt = AV_SAMPLE_FMT_S16P;
    a->stride = a->nb_samples * a->sample_size;
    a->read_only = 0;
    a->allow_realloc = 1;
    a->ptr_align = 1;
    a->samples_align = 1;
    a->name = "test_audio";

    for (int i = 0; i < a->planes; i++) {
        a->data[i] = a->buffer + i * (a->stride);
    }

    offset_size = 4096;
    for (int i = 0; i < 32; i++) {
        offset_data[i] = NULL;
    }
}