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

typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

typedef struct FFTContext FFTContext;

typedef struct DeNoiseChannel {
    int band_noise[15];
    double noise_band_auto_var[15];
    double noise_band_sample[15];
    double *amt;
    double *band_amt;
    double *band_excit;
    double *gain;
    double *prior;
    double *prior_band_excit;
    double *clean_data;
    double *noisy_data;
    double *out_samples;
    double *spread_function;
    double *abs_var;
    double *rel_var;
    double *min_abs_var;
    FFTComplex *fft_data;
    FFTContext *fft;
    FFTContext *ifft;
    double noise_band_norm[15];
    double noise_band_avr[15];
    double noise_band_avi[15];
    double noise_band_var[15];
    double sfm_threshold;
    double sfm_alpha;
    double sfm_results[3];
    int sfm_fail_flags[512];
    int sfm_fail_total;
} DeNoiseChannel;

typedef struct AVAudioFifo AVAudioFifo;

typedef struct AudioFFTDeNoiseContext {
    const AVClass *class;
    float noise_reduction;
    float noise_floor;
    int noise_type;
    char *band_noise_str;
    float residual_floor;
    int track_noise;
    int track_residual;
    int output_mode;
    float last_residual_floor;
    float last_noise_floor;
    float last_noise_reduction;
    float last_noise_balance;
    int64_t block_count;
    int64_t pts;
    int channels;
    int sample_noise;
    int sample_noise_start;
    int sample_noise_end;
    float sample_rate;
    int buffer_length;
    int fft_length;
    int fft_length2;
    int bin_count;
    int window_length;
    int sample_advance;
    int number_of_bands;
    int band_centre[15];
    int *bin2band;
    double *window;
    double *band_alpha;
    double *band_beta;
    DeNoiseChannel *dnch;
    double max_gain;
    double max_var;
    double gain_scale;
    double window_weight;
    double floor;
    double sample_floor;
    double auto_floor;
    int noise_band_edge[17];
    int noise_band_count;
    double matrix_a[25];
    double vector_b[5];
    double matrix_b[75];
    double matrix_c[75];
    AVAudioFifo *fifo;
} AudioFFTDeNoiseContext;

static DeNoiseChannel g_dnch;
static AudioFFTDeNoiseContext g_s;
static double g_band_excit[15];
static double g_band_amt[15];

AudioFFTDeNoiseContext *s = &g_s;
DeNoiseChannel *dnch = &g_dnch;

void init_vars() {
    for (int i = 0; i < 15; i++) {
        g_dnch.band_noise[i] = 0;
        g_dnch.noise_band_auto_var[i] = 0.0;
        g_dnch.noise_band_sample[i] = 0.0;
        g_dnch.noise_band_norm[i] = 0.0;
        g_dnch.noise_band_avr[i] = 0.0;
        g_dnch.noise_band_avi[i] = 0.0;
        g_dnch.noise_band_var[i] = 0.0;
        g_s.band_centre[i] = i * 100;
    }
    for (int i = 0; i < 17; i++) {
        g_s.noise_band_edge[i] = i * 8;
    }
    for (int i = 0; i < 25; i++) {
        g_s.matrix_a[i] = 1.0;
    }
    for (int i = 0; i < 5; i++) {
        g_s.vector_b[i] = 1.0;
    }
    for (int i = 0; i < 75; i++) {
        g_s.matrix_b[i] = 1.0;
        g_s.matrix_c[i] = 1.0;
    }
    for (int i = 0; i < 3; i++) {
        g_dnch.sfm_results[i] = 0.0;
    }
    for (int i = 0; i < 512; i++) {
        g_dnch.sfm_fail_flags[i] = 0;
    }

    g_dnch.band_excit = g_band_excit;
    g_dnch.band_amt = g_band_amt;
    g_dnch.amt = NULL;
    g_dnch.gain = NULL;
    g_dnch.prior = NULL;
    g_dnch.prior_band_excit = NULL;
    g_dnch.clean_data = NULL;
    g_dnch.noisy_data = NULL;
    g_dnch.out_samples = NULL;
    g_dnch.spread_function = NULL;
    g_dnch.abs_var = NULL;
    g_dnch.rel_var = NULL;
    g_dnch.min_abs_var = NULL;
    g_dnch.fft_data = NULL;
    g_dnch.fft = NULL;
    g_dnch.ifft = NULL;
    g_dnch.sfm_fail_total = 0;

    g_s.class = NULL;
    g_s.noise_reduction = 0.5f;
    g_s.noise_floor = -60.0f;
    g_s.noise_type = 0;
    g_s.band_noise_str = NULL;
    g_s.residual_floor = -50.0f;
    g_s.track_noise = 0;
    g_s.track_residual = 0;
    g_s.output_mode = 0;
    g_s.last_residual_floor = -50.0f;
    g_s.last_noise_floor = -60.0f;
    g_s.last_noise_reduction = 0.5f;
    g_s.last_noise_balance = 0.5f;
    g_s.block_count = 0;
    g_s.pts = 0;
    g_s.channels = 2;
    g_s.sample_noise = 0;
    g_s.sample_noise_start = 0;
    g_s.sample_noise_end = 0;
    g_s.sample_rate = 48000.0f;
    g_s.buffer_length = 4096;
    g_s.fft_length = 2048;
    g_s.fft_length2 = 1024;
    g_s.bin_count = 1025;
    g_s.window_length = 2048;
    g_s.sample_advance = 1024;
    g_s.number_of_bands = 15;
    g_s.bin2band = NULL;
    g_s.window = NULL;
    g_s.band_alpha = NULL;
    g_s.band_beta = NULL;
    g_s.dnch = &g_dnch;
    g_s.max_gain = 2.0;
    g_s.max_var = 1.0;
    g_s.gain_scale = 1.0;
    g_s.window_weight = 1.0;
    g_s.floor = 1e-6;
    g_s.sample_floor = 1e-6;
    g_s.auto_floor = 1e-6;
    g_s.noise_band_count = 15;
    g_s.fifo = NULL;
}