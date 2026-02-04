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

extern MixContext *s;
extern int i;
extern int active_inputs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; s->nb_inputs > 0 && i < s->nb_inputs; active_inputs += !!(s->input_state[i++] & 1));
}
