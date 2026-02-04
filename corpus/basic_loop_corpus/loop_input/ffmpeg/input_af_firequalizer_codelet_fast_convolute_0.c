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

extern FIREqualizerContext *restrict s;
extern float *restrict kernel_buf;
extern float *buf;
extern int k;

static FIREqualizerContext ctx;
static float *kernel_buf_data;
static float *buf_data;

void init_vars() {
    // Allocate data to make loop run about ~0.01 seconds on modern CPU
    // Loop runs (rdft_len / 2 - 1) iterations, each accessing up to 2*k+1 in buf
    // To hit ~10-50M operations, set rdft_len ~ 10M elements -> buf needs ~20M floats (~80MB)
    const int target_ops = 25000000; // ~25M operations
    const int len = (target_ops * 2) / 1; // approximate
    const int buf_size = 2 * (len / 2) + 2; // ensure we cover 2*k+1 safely

    kernel_buf_data = (float*)calloc(buf_size, sizeof(float));
    buf_data = (float*)calloc(buf_size, sizeof(float));

    if (!kernel_buf_data || !buf_data) {
        exit(1);
    }

    // Initialize kernel_buf with non-zero values to avoid no-op multiplication
    for (int i = 0; i < buf_size; i++) {
        kernel_buf_data[i] = 1.0f;
    }

    // Initialize buf with sample data
    for (int i = 0; i < buf_size; i++) {
        buf_data[i] = (float)(i % 1000) / 1000.0f;
    }

    // Set s->rdft_len so that the loop runs about (rdft_len/2 - 1) times
    ctx.rdft_len = len;

    // Assign external pointers
    s = &ctx;
    kernel_buf = kernel_buf_data;
    buf = buf_data;
    k = 0;
}

// Ensure variables are properly defined
FIREqualizerContext *restrict s = NULL;
float *restrict kernel_buf = NULL;
float *buf = NULL;
int k = 0;