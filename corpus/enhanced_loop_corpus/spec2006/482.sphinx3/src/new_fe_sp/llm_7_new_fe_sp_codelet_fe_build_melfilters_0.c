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
    int w;
    #pragma omp parallel for private(w)
    for (w = 0; w < MEL_FB->num_filters; ++w) {
        float leftfr_local, centerfr_local, rightfr_local;
        float fwidth_local, height_local = 0.0f;
        float leftslope_local = 0.0f, rightslope_local = 0.0f;
        int start_pt_local, i_local = 0;
        float freq_local;

        if (MEL_FB->doublewide == 1) {
            leftfr_local = (float)((int)((filt_edge[w] / dfreq) + 0.5)) * dfreq;
            centerfr_local = (float)((int)((filt_edge[w + 2] / dfreq) + 0.5)) * dfreq;
            rightfr_local = (float)((int)((filt_edge[w + 4] / dfreq) + 0.5)) * dfreq;
        } else {
            leftfr_local = (float)((int)((filt_edge[w] / dfreq) + 0.5)) * dfreq;
            centerfr_local = (float)((int)((filt_edge[w + 1] / dfreq) + 0.5)) * dfreq;
            rightfr_local = (float)((int)((filt_edge[w + 2] / dfreq) + 0.5)) * dfreq;
        }

        MEL_FB->left_apex[w] = leftfr_local;
        fwidth_local = rightfr_local - leftfr_local;
        height_local = 2.0f / fwidth_local;

        if (centerfr_local != leftfr_local) {
            leftslope_local = height_local / (centerfr_local - leftfr_local);
        }
        if (centerfr_local != rightfr_local) {
            rightslope_local = height_local / (centerfr_local - rightfr_local);
        }

        start_pt_local = (int)(leftfr_local / dfreq + 0.5);
        freq_local = (float32)start_pt_local * dfreq;

        for (i_local = 0; freq_local < centerfr_local; i_local++) {
            MEL_FB->filter_coeffs[w][i_local] = (freq_local - leftfr_local) * leftslope_local;
            freq_local += dfreq;
        }

        if (freq_local == centerfr_local) {
            MEL_FB->filter_coeffs[w][i_local] = height_local;
            freq_local += dfreq;
            i_local++;
        }

        for (; freq_local < rightfr_local; i_local++) {
            MEL_FB->filter_coeffs[w][i_local] = (freq_local - rightfr_local) * rightslope_local;
            freq_local += dfreq;
        }

        MEL_FB->width[w] = i_local;
    }
}
