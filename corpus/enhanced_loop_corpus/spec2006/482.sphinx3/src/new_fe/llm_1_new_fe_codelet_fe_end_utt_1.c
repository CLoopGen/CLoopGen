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
    if (FE->NUM_CEPSTRA > 0) {
        for (i = 0; i < 1; i++) {
            cepvector[0] = (float32)fr_fea[0];
        }
        for (i = 1; i < FE->NUM_CEPSTRA; i++) {
            cepvector[i] = (float32)fr_fea[i];
        }
    }
}
