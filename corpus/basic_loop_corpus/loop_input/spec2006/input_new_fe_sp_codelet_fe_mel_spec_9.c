#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

fe_t *FE;
double *spec;
double *mfspec;
int whichfilt;
int start;
int i;
float dfreq;

static float **alloc_float_matrix(int rows, int cols) {
    float **mat = malloc(rows * sizeof(float*));
    float *data = calloc(rows * cols, sizeof(float));
    for (int r = 0; r < rows; r++) {
        mat[r] = &data[r * cols];
    }
    return mat;
}

static void free_float_matrix(float **mat) {
    if (mat) {
        free(mat[0]);
        free(mat);
    }
}

void init_vars() {
    const int num_filters = 128;
    const int max_filter_width = 2048;
    const int total_fft_size = 1 << 20;

    FE = malloc(sizeof(fe_t));
    melfb_t *mel_fb = malloc(sizeof(melfb_t));

    FE->MEL_FB = mel_fb;
    mel_fb->num_filters = num_filters;
    mel_fb->fft_size = total_fft_size;
    dfreq = (float)(total_fft_size) / 16000.0f;

    mel_fb->left_apex = malloc(num_filters * sizeof(float));
    mel_fb->width = malloc(num_filters * sizeof(int32));
    mel_fb->filter_coeffs = alloc_float_matrix(num_filters, max_filter_width);

    spec = calloc(total_fft_size, sizeof(double));
    mfspec = calloc(num_filters, sizeof(double));

    float base_freq = 100.0f;
    float freq_step = 150.0f;

    for (int idx = 0; idx < num_filters; idx++) {
        float center = base_freq + idx * freq_step;
        mel_fb->left_apex[idx] = center * 0.9f;
        int w = (int)((center * 0.2f) / dfreq + 0.5f);
        mel_fb->width[idx] = (w > 0) ? w : 1;
        if (mel_fb->width[idx] > max_filter_width) {
            mel_fb->width[idx] = max_filter_width;
        }
        for (int j = 0; j < mel_fb->width[idx]; j++) {
            float x = (float)j / mel_fb->width[idx];
            mel_fb->filter_coeffs[idx][j] = 1.0f - fabsf(2.0f * x - 1.0f);
        }
    }

    FE->NUM_OVERFLOW_SAMPS = 0;
    FE->OVERFLOW_SAMPS = NULL;
    FE->START_FLAG = 1;
    FE->PRIOR = 0;
    FE->HAMMING_WINDOW = NULL;
}