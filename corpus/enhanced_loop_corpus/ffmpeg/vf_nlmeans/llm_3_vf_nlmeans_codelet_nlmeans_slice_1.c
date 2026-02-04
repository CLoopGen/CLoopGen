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


extern int x;
extern int y;
extern NLMeansContext *s;
extern  struct thread_data *td;
extern  ptrdiff_t src_linesize;
extern  int starty;
extern  int endy;
extern  uint32_t *ii;
extern  int dist_b;
extern  int dist_d;
extern  int dist_e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t wa_step = s->wa_linesize;
    const int stride = s->ii_lz_32;
    const uint8_t *src_base = td->src;
    struct weighted_avg *wa_base = s->wa;
    const uint32_t *ii_base = ii;

    for (y = starty; y < endy; y++) {
        int offset = y * stride;
        const uint8_t *src = src_base + y * src_linesize;
        struct weighted_avg *wa = wa_base + y * wa_step;
        for (x = td->startx; x < td->endx; x += 4) {
            const uint32_t *ii_ptr = ii_base + offset + x;
            uint32_t a0 = ii_ptr[0], b0 = ii_ptr[dist_b], d0 = ii_ptr[dist_d], e0 = ii_ptr[dist_e];
            uint32_t a1 = ii_ptr[1], b1 = ii_ptr[1 + dist_b], d1 = ii_ptr[1 + dist_d], e1 = ii_ptr[1 + dist_e];
            uint32_t a2 = ii_ptr[2], b2 = ii_ptr[2 + dist_b], d2 = ii_ptr[2 + dist_d], e2 = ii_ptr[2 + dist_e];
            uint32_t a3 = ii_ptr[3], b3 = ii_ptr[3 + dist_b], d3 = ii_ptr[3 + dist_d], e3 = ii_ptr[3 + dist_e];

            uint32_t patch_diff_sq0 = e0 - d0 - b0 + a0;
            uint32_t patch_diff_sq1 = e1 - d1 - b1 + a1;
            uint32_t patch_diff_sq2 = e2 - d2 - b2 + a2;
            uint32_t patch_diff_sq3 = e3 - d3 - b3 + a3;

            if (patch_diff_sq0 < s->max_meaningful_diff) {
                const float weight = s->weight_lut[patch_diff_sq0];
                wa[x + 0].total_weight += weight;
                wa[x + 0].sum += weight * src[x + 0];
            }
            if (patch_diff_sq1 < s->max_meaningful_diff) {
                const float weight = s->weight_lut[patch_diff_sq1];
                wa[x + 1].total_weight += weight;
                wa[x + 1].sum += weight * src[x + 1];
            }
            if (patch_diff_sq2 < s->max_meaningful_diff) {
                const float weight = s->weight_lut[patch_diff_sq2];
                wa[x + 2].total_weight += weight;
                wa[x + 2].sum += weight * src[x + 2];
            }
            if (patch_diff_sq3 < s->max_meaningful_diff) {
                const float weight = s->weight_lut[patch_diff_sq3];
                wa[x + 3].total_weight += weight;
                wa[x + 3].sum += weight * src[x + 3];
            }
        }
        for (; x < td->endx; x++) {
            const uint32_t a = ii_base[offset + x];
            const uint32_t b = ii_base[offset + x + dist_b];
            const uint32_t d = ii_base[offset + x + dist_d];
            const uint32_t e = ii_base[offset + x + dist_e];
            const uint32_t patch_diff_sq = e - d - b + a;
            if (patch_diff_sq < s->max_meaningful_diff) {
                const float weight = s->weight_lut[patch_diff_sq];
                wa[x].total_weight += weight;
                wa[x].sum += weight * src[x];
            }
        }
    }
}
