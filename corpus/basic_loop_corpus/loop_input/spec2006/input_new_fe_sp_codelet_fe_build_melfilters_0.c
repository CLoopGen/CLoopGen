#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

typedef int int32;
typedef float float32;

typedef struct {
    float sampling_rate;
    int32 num_cepstra;
    int32 num_filters;
    int32 fft_size;
    float lower_filt_freq;
    float upper_filt_freq;
    float **filter_coeffs;
    float **mel_cosine;
    float *left_apex;
    int32 *width;
    int32 doublewide;
} melfb_t;

melfb_t *MEL_FB;
int i;
int whichfilt;
int start_pt;
float leftfr;
float centerfr;
float rightfr;
float fwidth;
float height;
float *filt_edge;
float freq;
float dfreq;
float leftslope;
float rightslope;

void init_vars() {
    const int num_filters = 128;
    const int fft_size = 512;
    const int max_width = fft_size / 2 + 1;
    int j;

    MEL_FB = (melfb_t*)calloc(1, sizeof(melfb_t));
    MEL_FB->num_filters = num_filters;
    MEL_FB->fft_size = fft_size;
    MEL_FB->doublewide = 0;
    MEL_FB->sampling_rate = 16000.0f;
    MEL_FB->lower_filt_freq = 133.33f;
    MEL_FB->upper_filt_freq = 6855.497f;
    dfreq = MEL_FB->sampling_rate / MEL_FB->fft_size;

    filt_edge = (float*)calloc(num_filters + 4, sizeof(float));
    for (j = 0; j < num_filters + (MEL_FB->doublewide ? 4 : 2); ++j) {
        filt_edge[j] = (j < num_filters + (MEL_FB->doublewide ? 4 : 2)) ? 
            (133.33f + j * 50.0f) : 6855.497f;
    }

    MEL_FB->filter_coeffs = (float**)calloc(num_filters, sizeof(float*));
    for (j = 0; j < num_filters; ++j) {
        MEL_FB->filter_coeffs[j] = (float*)calloc(max_width, sizeof(float));
    }

    MEL_FB->mel_cosine = (float**)calloc(num_filters, sizeof(float*));
    for (j = 0; j < num_filters; ++j) {
        MEL_FB->mel_cosine[j] = (float*)calloc(max_width, sizeof(float));
    }

    MEL_FB->left_apex = (float*)calloc(num_filters, sizeof(float));
    MEL_FB->width = (int32*)calloc(num_filters, sizeof(int32));
}