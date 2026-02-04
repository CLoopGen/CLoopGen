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
for (int whichfilt = 0; whichfilt < MEL_FB->num_filters; ++whichfilt) {
    if (MEL_FB->doublewide == 1) {
        leftfr = (float)((int)((filt_edge[whichfilt] / dfreq) + 0.5)) * dfreq;
        centerfr = (float)((int)((filt_edge[whichfilt + 2] / dfreq) + 0.5)) * dfreq;
        rightfr = (float)((int)((filt_edge[whichfilt + 4] / dfreq) + 0.5)) * dfreq;
    } else {
        leftfr = (float)((int)((filt_edge[whichfilt] / dfreq) + 0.5)) * dfreq;
        centerfr = (float)((int)((filt_edge[whichfilt + 1] / dfreq) + 0.5)) * dfreq;
        rightfr = (float)((int)((filt_edge[whichfilt + 2] / dfreq) + 0.5)) * dfreq;
    }
    MEL_FB->left_apex[whichfilt] = leftfr;
    fwidth = rightfr - leftfr;
    height = 2 / (float)fwidth;
    if (centerfr != leftfr) {
        leftslope = height / (centerfr - leftfr);
    }
    if (centerfr != rightfr) {
        rightslope = height / (centerfr - rightfr);
    }
    start_pt = (int)(leftfr / dfreq + 0.5);
    freq = (float32)start_pt * dfreq;
    int i = 0;
    for (; freq < centerfr; freq += dfreq, i++) {
        MEL_FB->filter_coeffs[whichfilt][i] = (freq - leftfr) * leftslope;
    }
    if (freq == centerfr) {
        MEL_FB->filter_coeffs[whichfilt][i] = height;
        freq += dfreq;
        i++;
    }
    for (; freq < rightfr; freq += dfreq, i++) {
        MEL_FB->filter_coeffs[whichfilt][i] = (freq - rightfr) * rightslope;
    }
    MEL_FB->width[whichfilt] = i;
}
}
