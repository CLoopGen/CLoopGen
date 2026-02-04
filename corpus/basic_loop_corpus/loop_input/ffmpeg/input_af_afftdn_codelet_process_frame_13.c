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
double sum;

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

void init_vars() {
    sum = 1.5;

    dnch = (DeNoiseChannel*)calloc(1, sizeof(DeNoiseChannel));
    if (!dnch) exit(1);

    for (int i = 0; i < 15; i++) {
        dnch->band_noise[i] = i;
        dnch->noise_band_auto_var[i] = 1.0 + i;
        dnch->noise_band_sample[i] = 0.5 + i;
        dnch->noise_band_norm[i] = 0.1 + i;
        dnch->noise_band_avr[i] = 0.2 + i;
        dnch->noise_band_avi[i] = 0.3 + i;
        dnch->noise_band_var[i] = 0.4 + i;
    }

    dnch->sfm_threshold = 0.8;
    dnch->sfm_alpha = 0.9;
    for (int i = 0; i < 3; i++)
        dnch->sfm_results[i] = 0.7 + i;
    for (int i = 0; i < 512; i++)
        dnch->sfm_fail_flags[i] = i % 2;
    dnch->sfm_fail_total = 256;

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

    for (int i = 0; i < 1024; i++) {
        amt_data[i] = 0.1 * i;
        band_amt_data[i] = 0.2 * i;
        band_excit_data[i] = 0.3 * i;
        gain_data[i] = 0.4 * i;
        prior_data[i] = 0.5 * i;
        prior_band_excit_data[i] = 0.6 * i;
        clean_data_data[i] = 0.7 * i;
        noisy_data_data[i] = 0.8 * i;
        out_samples_data[i] = 0.9 * i;
        spread_function_data[i] = 1.0 * i;
        abs_var_data[i] = 1.1 * i;
        rel_var_data[i] = 1.2 * i;
        min_abs_var_data[i] = 1.3 * i;
        fft_data_data[i].re = 1.4 * i;
        fft_data_data[i].im = 1.5 * i;
    }
}