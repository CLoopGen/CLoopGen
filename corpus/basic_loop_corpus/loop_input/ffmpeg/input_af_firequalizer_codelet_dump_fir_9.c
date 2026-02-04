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

typedef struct AVOptionRanges AVOptionRanges;

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
int x;

void init_vars() {
    s = (FIREqualizerContext *)calloc(1, sizeof(FIREqualizerContext));
    if (!s) exit(1);

    s->fir_len = 131072;  // ~512KB of float data (131072 * sizeof(float) ≈ 512KB)
    s->rdft_len = 8192;

    s->analysis_buf = (float *)calloc(s->fir_len, sizeof(float));
    if (!s->analysis_buf) exit(1);

    for (int i = 0; i < s->fir_len; ++i) {
        s->analysis_buf[i] = (float)((i % 1000) + 1);
    }

    s->class = NULL;
    s->analysis_rdft = NULL;
    s->analysis_irdft = NULL;
    s->rdft = NULL;
    s->irdft = NULL;
    s->fft_ctx = NULL;
    s->cepstrum_rdft = NULL;
    s->cepstrum_irdft = NULL;
    s->analysis_rdft_len = 0;
    s->cepstrum_len = 0;
    s->dump_buf = NULL;
    s->kernel_tmp_buf = NULL;
    s->kernel_buf = NULL;
    s->cepstrum_buf = NULL;
    s->conv_buf = NULL;
    s->conv_idx = NULL;
    s->nsamples_max = 0;
    s->next_pts = 0;
    s->frame_nsamples_max = 0;
    s->remaining = 0;
    s->gain_cmd = NULL;
    s->gain_entry_cmd = NULL;
    s->gain = NULL;
    s->gain_entry = NULL;
    s->delay = 0.0;
    s->accuracy = 0.0;
    s->wfunc = 0;
    s->fixed = 0;
    s->multi = 0;
    s->zero_phase = 0;
    s->scale = 1;
    s->dumpfile = NULL;
    s->dumpscale = 0;
    s->fft2 = 0;
    s->min_phase = 0;
    s->nb_gain_entry = 0;
    s->gain_entry_err = 0;

    for (int i = 0; i < 4096; ++i) {
        s->gain_entry_tbl[i].freq = 0.0;
        s->gain_entry_tbl[i].gain = 0.0;
    }
}