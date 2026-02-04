#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

DeNoiseChannel *dnch;

static double amt_data[1024];
static double band_amt_data[1024];
static double band_excit_data[1024];
static double gain_data[1024];
static double prior_data[1024];
static double prior_band_excit_data[1024];
static double clean_data_data[1024];
static double noisy_data_data[1024];
static double out_samples_data[1024];
static double spread_function_data[1024];
static double abs_var_data[1024];
static double rel_var_data[1024];
static double min_abs_var_data[1024];
static FFTComplex fft_data_data[1024];

static DeNoiseChannel dnch_instance;

void init_vars() {
    dnch = &dnch_instance;
    dnch->amt = amt_data;
    dnch->band_amt = band_amt_data;
    dnch->band_excit = band_excit_data;
    dnch->gain = gain_data;
    dnch->prior = prior_data;
    dnch->prior_band_excit = prior_band_excit_data;
    dnch->clean_data = clean_data_data;
    dnch->noisy_data = noisy_data_data;
    dnch->out_samples = out_samples_data;
    dnch->spread_function = spread_function_data;
    dnch->abs_var = abs_var_data;
    dnch->rel_var = rel_var_data;
    dnch->min_abs_var = min_abs_var_data;
    dnch->fft_data = fft_data_data;
    dnch->fft = NULL;
    dnch->ifft = NULL;
    dnch->sfm_threshold = 0.5;
    dnch->sfm_alpha = 0.8;
    for (int i = 0; i < 3; i++) {
        dnch->sfm_results[i] = 0.0;
    }
    for (int i = 0; i < 512; i++) {
        dnch->sfm_fail_flags[i] = 0;
    }
    dnch->sfm_fail_total = 0;
    for (int i = 0; i < 15; i++) {
        dnch->band_noise[i] = 0;
        dnch->noise_band_auto_var[i] = 0.0;
        dnch->noise_band_sample[i] = 0.0;
        dnch->noise_band_norm[i] = 0.0;
        dnch->noise_band_avr[i] = 0.0;
        dnch->noise_band_avi[i] = 0.0;
        dnch->noise_band_var[i] = 0.0;
    }
}