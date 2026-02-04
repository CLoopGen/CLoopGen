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
        float edge1, edge2, edge3;
        if (MEL_FB->doublewide == 1) {
            edge1 = filt_edge[whichfilt];
            edge2 = filt_edge[whichfilt + 2];
            edge3 = filt_edge[whichfilt + 4];
        } else {
            edge1 = filt_edge[whichfilt];
            edge2 = filt_edge[whichfilt + 1];
            edge3 = filt_edge[whichfilt + 2];
        }

        leftfr = (float)((int)(edge1 / dfreq + 0.5)) * dfreq;
        centerfr = (float)((int)(edge2 / dfreq + 0.5)) * dfreq;
        rightfr = (float)((int)(edge3 / dfreq + 0.5)) * dfreq;

        MEL_FB->left_apex[whichfilt] = leftfr;
        fwidth = rightfr - leftfr;
        height = 2.0f / fwidth;

        leftslope = (centerfr > leftfr) ? (height / (centerfr - leftfr)) : 0.0f;
        rightslope = (centerfr < rightfr) ? (height / (centerfr - rightfr)) : 0.0f;

        int start_bin = (int)(leftfr / dfreq + 0.5);
        int center_bin = (int)(centerfr / dfreq + 0.5);
        int right_bin = (int)(rightfr / dfreq + 0.5);

        int idx = 0;
        for (int bin = start_bin; bin < right_bin; ++bin) {
            freq = bin * dfreq;
            if (bin < center_bin) {
                MEL_FB->filter_coeffs[whichfilt][idx] = (freq - leftfr) * leftslope;
            } else if (bin == center_bin) {
                MEL_FB->filter_coeffs[whichfilt][idx] = height;
            } else {
                MEL_FB->filter_coeffs[whichfilt][idx] = (freq - rightfr) * rightslope;
            }
            idx++;
        }
        MEL_FB->width[whichfilt] = idx;
    }
}
