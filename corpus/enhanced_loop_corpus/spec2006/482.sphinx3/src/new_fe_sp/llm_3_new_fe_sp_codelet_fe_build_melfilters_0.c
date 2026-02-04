#include <stdio.h>

#include <inttypes.h>

typedef int int32;

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

typedef float float32;

extern melfb_t *MEL_FB;
extern int i;
extern int whichfilt;
extern int start_pt;
extern float leftfr;
extern float centerfr;
extern float rightfr;
extern float fwidth;
extern float height;
extern float *filt_edge;
extern float freq;
extern float dfreq;
extern float leftslope;
extern float rightslope;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (whichfilt = 0; whichfilt < MEL_FB->num_filters; ++whichfilt) {
    int idx = whichfilt;
    int double_offset = MEL_FB->doublewide ? 2 : 1;

    leftfr = (float)((int)((filt_edge[idx] / dfreq) + 0.5)) * dfreq;
    centerfr = (float)((int)((filt_edge[idx + double_offset] / dfreq) + 0.5)) * dfreq;
    rightfr = (float)((int)((filt_edge[idx + 2 * double_offset] / dfreq) + 0.5)) * dfreq;

    MEL_FB->left_apex[idx] = leftfr;
    fwidth = rightfr - leftfr;
    height = 2.0f / fwidth;

    leftslope = (centerfr != leftfr) ? (height / (centerfr - leftfr)) : 0.0f;
    rightslope = (centerfr != rightfr) ? (height / (centerfr - rightfr)) : 0.0f;

    start_pt = (int)(leftfr / dfreq + 0.5);
    freq = (float32)start_pt * dfreq;
    i = 0;

    int center_idx = (int)(centerfr / dfreq + 0.5);
    int right_idx = (int)(rightfr / dfreq + 0.5);

    // First segment: from left to center (exclusive)
    for (int k = start_pt; k < center_idx; ++k, ++i) {
        float linear_freq = (float32)k * dfreq;
        MEL_FB->filter_coeffs[whichfilt][i] = (linear_freq - leftfr) * leftslope;
    }

    // Peak at center
    if (center_idx * dfreq == centerfr) {
        MEL_FB->filter_coeffs[whichfilt][i] = height;
        i++;
    }

    // Second segment: from center+1 to right (exclusive)
    for (int k = center_idx + 1; k < right_idx; ++k, ++i) {
        float linear_freq = (float32)k * dfreq;
        MEL_FB->filter_coeffs[whichfilt][i] = (linear_freq - rightfr) * rightslope;
    }

    MEL_FB->width[whichfilt] = i;
}
}
