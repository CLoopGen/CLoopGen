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

typedef struct RDFTContext RDFTContext;

typedef struct FFTContext FFTContext;

typedef struct OverlapIndex {
    int buf_idx;
    int overlap_idx;
} OverlapIndex;

typedef struct GainEntry {
    double freq;
    double gain;
} GainEntry;

typedef struct FIREqualizerContext {
    const AVClass *class;
    RDFTContext *analysis_rdft;
    RDFTContext *analysis_irdft;
    RDFTContext *rdft;
    RDFTContext *irdft;
    FFTContext *fft_ctx;
    RDFTContext *cepstrum_rdft;
    RDFTContext *cepstrum_irdft;
    int analysis_rdft_len;
    int rdft_len;
    int cepstrum_len;
    float *analysis_buf;
    float *dump_buf;
    float *kernel_tmp_buf;
    float *kernel_buf;
    float *cepstrum_buf;
    float *conv_buf;
    OverlapIndex *conv_idx;
    int fir_len;
    int nsamples_max;
    int64_t next_pts;
    int frame_nsamples_max;
    int remaining;
    char *gain_cmd;
    char *gain_entry_cmd;
    const char *gain;
    const char *gain_entry;
    double delay;
    double accuracy;
    int wfunc;
    int fixed;
    int multi;
    int zero_phase;
    int scale;
    char *dumpfile;
    int dumpscale;
    int fft2;
    int min_phase;
    int nb_gain_entry;
    int gain_entry_err;
    GainEntry gain_entry_tbl[4096];
} FIREqualizerContext;

FIREqualizerContext *s;
int rdft_bits;

static AVClass av_class_s = { .class_name = "firequalizer" };
static struct AVOption av_option_s = { .name = "example", .type = AV_OPT_TYPE_STRING };

void init_vars() {
    s = (FIREqualizerContext *)calloc(1, sizeof(FIREqualizerContext));
    if (!s) return;

    s->class = &av_class_s;
    s->fir_len = 512;
    s->analysis_rdft_len = 0;
    s->cepstrum_len = 0;
    s->next_pts = 0;
    s->frame_nsamples_max = 0;
    s->remaining = 0;
    s->delay = 0.0;
    s->accuracy = 1e-3;
    s->wfunc = 1;
    s->fixed = 0;
    s->multi = 0;
    s->zero_phase = 0;
    s->scale = 1;
    s->dumpscale = 1;
    s->fft2 = 0;
    s->min_phase = 0;
    s->nb_gain_entry = 0;
    s->gain_entry_err = 0;

    size_t kernel_size = 1 << 16;
    s->rdft_len = kernel_size;
    s->nsamples_max = s->rdft_len - s->fir_len + 1;

    s->analysis_buf = (float *)calloc(kernel_size, sizeof(float));
    s->dump_buf = (float *)calloc(kernel_size, sizeof(float));
    s->kernel_tmp_buf = (float *)calloc(kernel_size, sizeof(float));
    s->kernel_buf = (float *)calloc(kernel_size, sizeof(float));
    s->cepstrum_buf = (float *)calloc(kernel_size, sizeof(float));
    s->conv_buf = (float *)calloc(kernel_size * 2, sizeof(float));
    s->conv_idx = (OverlapIndex *)calloc(kernel_size * 2, sizeof(OverlapIndex));

    for (int i = 0; i < 4096; i++) {
        s->gain_entry_tbl[i].freq = 20.0 * i;
        s->gain_entry_tbl[i].gain = 0.0;
    }

    s->gain_cmd = (char *)calloc(256, sizeof(char));
    s->gain_entry_cmd = (char *)calloc(256, sizeof(char));
    s->gain = "default";
    s->gain_entry = "entry";

    rdft_bits = 4;
}