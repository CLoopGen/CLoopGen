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

typedef struct AVLFG {
    unsigned int state[64];
    int index;
} AVLFG;

typedef struct AVComponentDescriptor {
    int plane;
    int step;
    int offset;
    int shift;
    int depth;
    int step_minus1;
    int depth_minus1;
    int offset_plus1;
} AVComponentDescriptor;

typedef struct AVPixFmtDescriptor {
    const char *name;
    uint8_t nb_components;
    uint8_t log2_chroma_w;
    uint8_t log2_chroma_h;
    uint64_t flags;
    AVComponentDescriptor comp[4];
    const char *alias;
} AVPixFmtDescriptor;

typedef struct ELBGContext {
    const AVClass *class;
    AVLFG lfg;
    int64_t lfg_seed;
    int max_steps_nb;
    int *codeword;
    int codeword_length;
    int *codeword_closest_codebook_idxs;
    int *codebook;
    int codebook_length;
    const AVPixFmtDescriptor *pix_desc;
    uint8_t rgba_map[4];
    int pal8;
} ELBGContext;

ELBGContext *elbg;
int i;
uint32_t *pal;

void init_vars() {
    elbg = (ELBGContext*)calloc(1, sizeof(ELBGContext));
    if (!elbg) return;

    elbg->codebook_length = 65536; // ~1MB of output: 65536 * 4 bytes per pixel

    elbg->codebook = (int*)calloc(elbg->codebook_length * 3, sizeof(int));
    if (!elbg->codebook) return;

    pal = (uint32_t*)calloc(elbg->codebook_length, sizeof(uint32_t));
    if (!pal) return;

    for (int j = 0; j < elbg->codebook_length * 3; j++) {
        elbg->codebook[j] = rand() & 0xFF;
    }

    elbg->pal8 = 0;
    elbg->rgba_map[0] = 0;
    elbg->rgba_map[1] = 1;
    elbg->rgba_map[2] = 2;
    elbg->rgba_map[3] = 3;

    static const AVClass av_class_instance = {
        .class_name = "elbg",
        .category = AV_CLASS_CATEGORY_FILTER
    };
    elbg->class = &av_class_instance;

    static const AVPixFmtDescriptor pix_desc_instance = {
        .name = "rgb24",
        .nb_components = 3,
        .log2_chroma_w = 0,
        .log2_chroma_h = 0,
        .flags = 0
    };
    elbg->pix_desc = &pix_desc_instance;

    for (int k = 0; k < 64; k++) {
        elbg->lfg.state[k] = rand();
    }
    elbg->lfg.index = 0;
    elbg->lfg_seed = 12345;
    elbg->max_steps_nb = 1000;
}