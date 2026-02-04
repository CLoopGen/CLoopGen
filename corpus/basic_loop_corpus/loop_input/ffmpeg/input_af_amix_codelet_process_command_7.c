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

typedef struct AVFloatDSPContext {
    void (*vector_fmul)(float *, const float *, const float *, int);
    void (*vector_fmac_scalar)(float *, const float *, float, int);
    void (*vector_dmac_scalar)(double *, const double *, double, int);
    void (*vector_fmul_scalar)(float *, const float *, float, int);
    void (*vector_dmul_scalar)(double *, const double *, double, int);
    void (*vector_fmul_window)(float *, const float *, const float *, const float *, int);
    void (*vector_fmul_add)(float *, const float *, const float *, const float *, int);
    void (*vector_fmul_reverse)(float *, const float *, const float *, int);
    void (*butterflies_float)(float *restrict, float *restrict, int);
    float (*scalarproduct_float)(const float *, const float *, int);
    void (*vector_dmul)(double *, const double *, const double *, int);
} AVFloatDSPContext;

typedef struct AVAudioFifo AVAudioFifo;

typedef struct FrameInfo {
    int nb_samples;
    int64_t pts;
    struct FrameInfo *next;
} FrameInfo;

typedef struct FrameList {
    int nb_frames;
    int nb_samples;
    FrameInfo *list;
    FrameInfo *end;
} FrameList;

typedef struct MixContext {
    const AVClass *class;
    AVFloatDSPContext *fdsp;
    int nb_inputs;
    int active_inputs;
    int duration_mode;
    float dropout_transition;
    char *weights_str;
    int nb_channels;
    int sample_rate;
    int planar;
    AVAudioFifo **fifos;
    uint8_t *input_state;
    float *input_scale;
    float *weights;
    float weight_sum;
    float *scale_norm;
    int64_t next_pts;
    FrameList *frame_list;
} MixContext;

MixContext *s;

void init_vars() {
    const int data_size_mb = 128;
    const int estimated_avg_input_size = 1024;
    s = (MixContext *)calloc(1, sizeof(MixContext));
    s->nb_inputs = (data_size_mb * 1024 * 1024) / (sizeof(float) * 3 + sizeof(uint8_t)) / estimated_avg_input_size;
    if (s->nb_inputs < 1) s->nb_inputs = 1;

    s->class = (AVClass *)calloc(1, sizeof(AVClass));
    s->fdsp = (AVFloatDSPContext *)calloc(1, sizeof(AVFloatDSPContext));
    s->active_inputs = s->nb_inputs;
    s->duration_mode = 0;
    s->dropout_transition = 0.0f;
    s->weights_str = (char *)calloc(1, 16);
    s->nb_channels = 2;
    s->sample_rate = 48000;
    s->planar = 1;

    s->fifos = (AVAudioFifo **)calloc(s->nb_inputs, sizeof(AVAudioFifo *));
    s->input_state = (uint8_t *)calloc(s->nb_inputs, sizeof(uint8_t));
    s->input_scale = (float *)calloc(s->nb_inputs, sizeof(float));
    s->weights = (float *)calloc(s->nb_inputs, sizeof(float));
    s->scale_norm = (float *)calloc(s->nb_inputs, sizeof(float));

    for (int i = 0; i < s->nb_inputs; i++) {
        s->weights[i] = (i % 3 == 0) ? -1.5f : 2.0f;
    }
    s->weight_sum = 10.0f;

    s->next_pts = 0;
    s->frame_list = (FrameList *)calloc(1, sizeof(FrameList));
}

void loop();