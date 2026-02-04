#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef short int16;

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

typedef struct {
    float SAMPLING_RATE;
    int32 FRAME_RATE;
    int32 FRAME_SHIFT;
    float WINDOW_LENGTH;
    int32 FRAME_SIZE;
    int32 FFT_SIZE;
    int32 FB_TYPE;
    int32 NUM_CEPSTRA;
    float PRE_EMPHASIS_ALPHA;
    int16 *OVERFLOW_SAMPS;
    int32 NUM_OVERFLOW_SAMPS;
    melfb_t *MEL_FB;
    int32 START_FLAG;
    int16 PRIOR;
    double *HAMMING_WINDOW;
} fe_t;

extern fe_t *FE;
extern double *spec;
extern double *mfspec;
extern int whichfilt;
extern int start;
extern int i;
extern float dfreq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int whichfilt, start, i;
    int num_filters = FE->MEL_FB->num_filters;
    float dfreq_inv = 1.0f / dfreq;
    float *left_apex = FE->MEL_FB->left_apex;
    int32 *width = FE->MEL_FB->width;
    float **filter_coeffs = FE->MEL_FB->filter_coeffs;
    double *spec_ptr = spec;

    for (whichfilt = 0; whichfilt < num_filters; whichfilt++) {
        start = (int)(left_apex[whichfilt] * dfreq_inv + 0.5f);
        double sum = 0.0;
        int w = width[whichfilt];
        float *coeffs = filter_coeffs[whichfilt];
        
        for (i = 0; i < w; i++) {
            sum += coeffs[i] * spec_ptr[start + i];
        }
        mfspec[whichfilt] = sum;
    }
}
