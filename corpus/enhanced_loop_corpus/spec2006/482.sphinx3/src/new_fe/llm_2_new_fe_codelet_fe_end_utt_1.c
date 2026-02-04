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

typedef float float32;

extern fe_t *FE;
extern float32 *cepvector;
extern int i;
extern double *fr_fea;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolling the loop to handle pairs of elements
    int32 n = FE->NUM_CEPSTRA;
    int stride = 2;
    for (i = 0; i < n; i += stride) {
        if (i < n) cepvector[i] = (float32)fr_fea[i];
        if (i + 1 < n) cepvector[i + 1] = (float32)fr_fea[i + 1];
    }
}
