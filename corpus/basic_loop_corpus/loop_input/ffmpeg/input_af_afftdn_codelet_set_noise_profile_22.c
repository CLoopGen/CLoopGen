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
double d1;
int i;

static size_t data_size = 1 << 20; // 1MB of data

double* alloc_double_array(size_t len) {
    double *arr = malloc(len * sizeof(double));
    for (size_t k = 0; k < len; ++k)
        arr[k] = (double)(k % 1000) / 100.0;
    return arr;
}

FFTComplex* alloc_fft_complex_array(size_t len) {
    FFTComplex *arr = malloc(len * sizeof(FFTComplex));
    for (size_t k = 0; k < len; ++k) {
        arr[k].re = (FFTSample)((k % 1000) / 100.0);
        arr[k].im = (FFTSample)((k % 500) / 100.0);
    }
    return arr;
}

void init_vars() {
    dnch = malloc(sizeof(DeNoiseChannel));
    if (!dnch) exit(1);

    for (int idx = 0; idx < 15; ++idx) {
        dnch->band_noise[idx] = -5 + idx;
        dnch->noise_band_auto_var[idx] = 0.1 + idx * 0.01;
        dnch->noise_band_sample[idx] = 0.2 + idx * 0.02;
        dnch->noise_band_norm[idx] = 0.3 + idx * 0.03;
        dnch->noise_band_avr[idx] = 0.4 + idx * 0.04;
        dnch->noise_band_avi[idx] = 0.5 + idx * 0.05;
        dnch->noise_band_var[idx] = 0.6 + idx * 0.06;
    }

    dnch->amt = alloc_double_array(data_size);
    dnch->band_amt = alloc_double_array(data_size);
    dnch->band_excit = alloc_double_array(data_size);
    dnch->gain = alloc_double_array(data_size);
    dnch->prior = alloc_double_array(data_size);
    dnch->prior_band_excit = alloc_double_array(data_size);
    dnch->clean_data = alloc_double_array(data_size);
    dnch->noisy_data = alloc_double_array(data_size);
    dnch->out_samples = alloc_double_array(data_size);
    dnch->spread_function = alloc_double_array(data_size);
    dnch->abs_var = alloc_double_array(data_size);
    dnch->rel_var = alloc_double_array(data_size);
    dnch->min_abs_var = alloc_double_array(data_size);
    dnch->fft_data = alloc_fft_complex_array(data_size);

    dnch->fft = NULL;
    dnch->ifft = NULL;

    dnch->sfm_threshold = 0.7;
    dnch->sfm_alpha = 0.9;
    for (int idx = 0; idx < 3; ++idx)
        dnch->sfm_results[idx] = 0.1 + idx * 0.05;
    for (int idx = 0; idx < 512; ++idx)
        dnch->sfm_fail_flags[idx] = 0;
    dnch->sfm_fail_total = 0;

    d1 = 100.0;
    i = 5;
}