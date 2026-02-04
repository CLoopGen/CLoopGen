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
float weight_sum;
int i;

void init_vars() {
    s = malloc(sizeof(MixContext));
    if (!s) return;

    s->nb_inputs = 1000000;
    s->duration_mode = 0;
    s->dropout_transition = 0.0f;
    s->nb_channels = 2;
    s->sample_rate = 48000;
    s->planar = 1;
    s->weight_sum = 0.0f;
    s->next_pts = 0;

    s->input_state = malloc(s->nb_inputs * sizeof(uint8_t));
    s->weights = malloc(s->nb_inputs * sizeof(float));
    s->input_scale = malloc(s->nb_inputs * sizeof(float));
    s->scale_norm = malloc(s->nb_inputs * sizeof(float));
    s->fifos = calloc(s->nb_inputs, sizeof(AVAudioFifo*));

    for (int j = 0; j < s->nb_inputs; j++) {
        s->input_state[j] = j % 3 ? 1 : 0;
        s->weights[j] = (j % 7) * 0.5f - 1.5f;
        s->input_scale[j] = 1.0f;
        s->scale_norm[j] = 1.0f;
    }

    s->class = NULL;
    s->fdsp = NULL;
    s->weights_str = NULL;
    s->active_inputs = 0;
    s->frame_list = NULL;

    weight_sum = 0.0f;
    i = 0;
}