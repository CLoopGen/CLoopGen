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
        float local_leftfr, local_centerfr, local_rightfr;
        float local_fwidth, local_height = 0.0f;
        float local_leftslope = 0.0f, local_rightslope = 0.0f;
        int local_start_pt;
        float freq_val;
        int idx = 0;

        if (MEL_FB->doublewide == 1) {
            local_leftfr = (float)((int)((filt_edge[whichfilt] / dfreq) + 0.5)) * dfreq;
            local_centerfr = (float)((int)((filt_edge[whichfilt + 2] / dfreq) + 0.5)) * dfreq;
            local_rightfr = (float)((int)((filt_edge[whichfilt + 4] / dfreq) + 0.5)) * dfreq;
        } else {
            local_leftfr = (float)((int)((filt_edge[whichfilt] / dfreq) + 0.5)) * dfreq;
            local_centerfr = (float)((int)((filt_edge[whichfilt + 1] / dfreq) + 0.5)) * dfreq;
            local_rightfr = (float)((int)((filt_edge[whichfilt + 2] / dfreq) + 0.5)) * dfreq;
        }

        MEL_FB->left_apex[whichfilt] = local_leftfr;
        local_fwidth = local_rightfr - local_leftfr;
        local_height = 2.0f / local_fwidth;

        if (local_centerfr != local_leftfr) {
            local_leftslope = local_height / (local_centerfr - local_leftfr);
        }
        if (local_centerfr != local_rightfr) {
            local_rightslope = local_height / (local_centerfr - local_rightfr);
        }

        local_start_pt = (int)(local_leftfr / dfreq + 0.5);
        freq_val = (float32)local_start_pt * dfreq;

        for (idx = 0; freq_val < local_centerfr; idx++) {
            MEL_FB->filter_coeffs[whichfilt][idx] = (freq_val - local_leftfr) * local_leftslope;
            freq_val += dfreq;
        }

        if (freq_val == local_centerfr) {
            MEL_FB->filter_coeffs[whichfilt][idx] = local_height;
            freq_val += dfreq;
            idx++;
        }

        for (; freq_val < local_rightfr; idx++) {
            MEL_FB->filter_coeffs[whichfilt][idx] = (freq_val - local_rightfr) * local_rightslope;
            freq_val += dfreq;
        }

        MEL_FB->width[whichfilt] = idx;
    }
}
