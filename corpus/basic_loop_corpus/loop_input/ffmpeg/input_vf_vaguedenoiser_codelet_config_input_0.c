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

typedef struct VagueDenoiserContext {
    const AVClass *class;
    float threshold;
    float percent;
    int method;
    int type;
    int nsteps;
    int planes;
    int depth;
    int bpc;
    int peak;
    int nb_planes;
    int planeheight[4];
    int planewidth[4];
    float *block;
    float *in;
    float *out;
    float *tmp;
    int hlowsize[4][32];
    int hhighsize[4][32];
    int vlowsize[4][32];
    int vhighsize[4][32];
    void (*thresholding)(float *, const int, const int, const int, const float, const float);
} VagueDenoiserContext;

static AVClass av_class = {
    .class_name = "vague_denoiser",
    .category = AV_CLASS_CATEGORY_FILTER
};

static struct AVOption options[] = {
    { NULL }
};

static void dummy_thresholding(float *data, const int a, const int b, const int c, const float d, const float e) {
}

static float *allocate_float_array(size_t size) {
    float *ptr = (float *)calloc(size, sizeof(float));
    return ptr;
}

VagueDenoiserContext *s;
int p;
int i;

void init_vars() {
    s = (VagueDenoiserContext *)calloc(1, sizeof(VagueDenoiserContext));
    if (!s) exit(1);

    s->class = &av_class;
    s->threshold = 0.1f;
    s->percent = 50.0f;
    s->method = 1;
    s->type = 0;
    s->nsteps = 5; 
    s->planes = 4;
    s->depth = 8;
    s->bpc = 8;
    s->peak = 255;
    s->nb_planes = 3;

    s->planewidth[0] = 1920;
    s->planewidth[1] = 960;
    s->planewidth[2] = 960;
    s->planewidth[3] = 1920;

    s->planeheight[0] = 1080;
    s->planeheight[1] = 540;
    s->planeheight[2] = 540;
    s->planeheight[3] = 1080;

    size_t block_size = 1920 * 1080;
    s->block = allocate_float_array(block_size);
    s->in = allocate_float_array(block_size);
    s->out = allocate_float_array(block_size);
    s->tmp = allocate_float_array(block_size);

    s->thresholding = dummy_thresholding;

    for (int p = 0; p < 4; p++) {
        for (int j = 0; j < 32; j++) {
            s->hlowsize[p][j] = 0;
            s->hhighsize[p][j] = 0;
            s->vlowsize[p][j] = 0;
            s->vhighsize[p][j] = 0;
        }
    }
}