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

union av_default_val {
    int64_t i64;
    double dbl;
    const char *str;
    struct { int num; int den; } q;
};

struct AVOption {
    const char *name;
    const char *help;
    int offset;
    enum AVOptionType type;
    union av_default_val default_val;
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

struct weighted_avg {
    float total_weight;
    float sum;
};

typedef struct NLMeansDSPContext {
    void (*compute_safe_ssd_integral_image)(uint32_t *, ptrdiff_t, const uint8_t *, ptrdiff_t, const uint8_t *, ptrdiff_t, int, int);
} NLMeansDSPContext;

typedef struct NLMeansContext {
    const AVClass *class;
    int nb_planes;
    int chroma_w;
    int chroma_h;
    double pdiff_scale;
    double sigma;
    int patch_size;
    int patch_hsize;
    int patch_size_uv;
    int patch_hsize_uv;
    int research_size;
    int research_hsize;
    int research_size_uv;
    int research_hsize_uv;
    uint32_t *ii_orig;
    uint32_t *ii;
    int ii_w;
    int ii_h;
    ptrdiff_t ii_lz_32;
    struct weighted_avg *wa;
    ptrdiff_t wa_linesize;
    float *weight_lut;
    uint32_t max_meaningful_diff;
    NLMeansDSPContext dsp;
} NLMeansContext;

struct thread_data {
    const uint8_t *src;
    ptrdiff_t src_linesize;
    int startx;
    int starty;
    int endx;
    int endy;
    const uint32_t *ii_start;
    int p;
};

int x;
int y;
NLMeansContext *s;
struct thread_data *td;
ptrdiff_t src_linesize;
int starty;
int endy;
uint32_t *ii;
int dist_b;
int dist_e;
int dist_d;

static uint8_t *src_buffer;
static uint32_t *ii_buffer;
static struct weighted_avg *wa_buffer;
static float *weight_lut_buffer;
static AVClass avclass_instance;
static NLMeansContext s_instance;
static struct thread_data td_instance;

void init_vars(void) {
    const int width = 1024;
    const int height = 1024;
    const int patch_size = 5;
    const int research_size = 11;

    src_linesize = width;
    starty = patch_size / 2;
    endy = height - patch_size / 2;

    dist_b = width * (research_size / 2);
    dist_d = research_size / 2;
    dist_e = dist_b + dist_d;

    s = &s_instance;
    td = &td_instance;

    src_buffer = calloc(width * height, sizeof(uint8_t));
    ii_buffer = calloc((width + research_size) * (height + research_size), sizeof(uint32_t));
    wa_buffer = calloc(width * height, sizeof(struct weighted_avg));
    weight_lut_buffer = calloc(65536, sizeof(float));

    for (int i = 0; i < 65536; i++) {
        weight_lut_buffer[i] = 1.0f / (1.0f + i * 0.001f);
    }

    s->ii = ii_buffer;
    s->ii_lz_32 = width + research_size;
    s->wa = wa_buffer;
    s->wa_linesize = width;
    s->weight_lut = weight_lut_buffer;
    s->max_meaningful_diff = 65535;
    s->patch_hsize = patch_size / 2;
    s->research_hsize = research_size / 2;

    td->src = src_buffer;
    td->src_linesize = src_linesize;
    td->startx = patch_size / 2;
    td->starty = starty;
    td->endx = width - patch_size / 2;
    td->endy = endy;
    td->ii_start = ii_buffer;

    ii = ii_buffer;
}