#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

fe_t *FE;
float32 *cepvector;
int i;
double *fr_fea;

void init_vars() {
    FE = (fe_t*)malloc(sizeof(fe_t));
    if (!FE) exit(1);

    FE->NUM_CEPSTRA = 13000; // Adjusted to ensure ~0.01 sec runtime

    cepvector = (float32*)malloc(FE->NUM_CEPSTRA * sizeof(float32));
    fr_fea = (double*)malloc(FE->NUM_CEPSTRA * sizeof(double));

    if (!cepvector || !fr_fea) exit(1);

    for (int j = 0; j < FE->NUM_CEPSTRA; j++) {
        fr_fea[j] = (double)(j + 1);
        cepvector[j] = 0.0f;
    }

    FE->OVERFLOW_SAMPS = NULL;
    FE->NUM_OVERFLOW_SAMPS = 0;
    FE->MEL_FB = NULL;
    FE->START_FLAG = 0;
    FE->PRIOR = 0;
    FE->HAMMING_WINDOW = NULL;

    FE->SAMPLING_RATE = 16000.0f;
    FE->FRAME_RATE = 100;
    FE->FRAME_SHIFT = 160;
    FE->WINDOW_LENGTH = 0.025f;
    FE->FRAME_SIZE = 400;
    FE->FFT_SIZE = 512;
    FE->FB_TYPE = 1;
    FE->PRE_EMPHASIS_ALPHA = 0.97f;
}