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
    // Variant 1: Consecutive Memory Access via Pointer Arithmetic
    // Instead of indexing spec[] with a strided start+i pattern, we use a pointer that advances consecutively
    // This improves spatial locality and may enable better vectorization
    float *filter_coeffs_ptr;
    double *spec_ptr;
    for (whichfilt = 0; whichfilt < FE->MEL_FB->num_filters; whichfilt++) {
        start = (int)(FE->MEL_FB->left_apex[whichfilt] / dfreq + 0.5);
        mfspec[whichfilt] = 0;
        filter_coeffs_ptr = FE->MEL_FB->filter_coeffs[whichfilt];
        spec_ptr = &spec[start];
        for (i = 0; i < FE->MEL_FB->width[whichfilt]; i++) {
            mfspec[whichfilt] += filter_coeffs_ptr[i] * spec_ptr[i];
        }
    }
}
