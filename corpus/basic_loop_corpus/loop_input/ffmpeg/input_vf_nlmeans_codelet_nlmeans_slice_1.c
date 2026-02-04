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
int dist_d;
int dist_e;

static uint8_t *src_buffer;
static struct weighted_avg *wa_buffer;
static float *weight_lut_buffer;
static uint32_t *ii_buffer;

void init_vars() {
    // Allocate buffers with sufficient size to make loop take ~0.01s
    // Target: ~10-20 million pixels (empirical for 0.01s on modern CPU)
    const int width = 2048;
    const int height = 4096;
    const int ii_stride = width + 64;  // padding to avoid out-of-bounds
    const int wa_stride = width;
    
    src_buffer = aligned_alloc(32, (size_t)height * width * sizeof(uint8_t));
    wa_buffer = aligned_alloc(32, (size_t)height * wa_stride * sizeof(struct weighted_avg));
    weight_lut_buffer = aligned_alloc(32, 65536 * sizeof(float));
    ii_buffer = aligned_alloc(32, (size_t)(height + 16) * ii_stride * sizeof(uint32_t));

    // Initialize weight lut
    for (int i = 0; i < 65536; i++) {
        weight_lut_buffer[i] = 1.0f / (1.0f + i * 0.0001f);
    }

    // Initialize s (NLMeansContext)
    s = malloc(sizeof(NLMeansContext));
    s->class = NULL;
    s->nb_planes = 1;
    s->chroma_w = width >> 1;
    s->chroma_h = height >> 1;
    s->pdiff_scale = 1.0;
    s->sigma = 25.0;
    s->patch_size = 7;
    s->patch_hsize = 3;
    s->patch_size_uv = 7;
    s->patch_hsize_uv = 3;
    s->research_size = 21;
    s->research_hsize = 10;
    s->research_size_uv = 21;
    s->research_hsize_uv = 10;
    s->ii_orig = ii_buffer;
    s->ii = ii_buffer;
    s->ii_w = ii_stride;
    s->ii_h = height + 16;
    s->ii_lz_32 = ii_stride;
    s->wa = wa_buffer;
    s->wa_linesize = wa_stride;
    s->weight_lut = weight_lut_buffer;
    s->max_meaningful_diff = 65535;
    s->dsp.compute_safe_ssd_integral_image = NULL;

    // Initialize thread data
    td = malloc(sizeof(struct thread_data));
    td->src = src_buffer;
    td->src_linesize = width;
    td->startx = 8;
    td->starty = 8;
    td->endx = width - 8;
    td->endy = height - 8;
    td->ii_start = ii_buffer;
    td->p = 0;

    // Set global variables used in loop
    src_linesize = width;
    starty = td->starty;
    endy = td->endy;
    ii = ii_buffer;
    dist_b = s->patch_hsize * ii_stride;
    dist_d = s->research_hsize * ii_stride;
    dist_e = dist_b + dist_d;

    // Initialize integral image and weighted avg buffers
    for (int i = 0; i < (height + 16) * ii_stride; i++) {
        ii_buffer[i] = rand() % 1000;
    }
    for (int i = 0; i < height * wa_stride; i++) {
        wa_buffer[i].total_weight = 0.0f;
        wa_buffer[i].sum = 0.0f;
    }
}