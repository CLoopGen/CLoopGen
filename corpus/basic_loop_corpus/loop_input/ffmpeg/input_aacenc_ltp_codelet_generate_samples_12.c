#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float INTFLOAT;

typedef struct LongTermPrediction {
    int8_t present;
    int16_t lag;
    int coef_idx;
    INTFLOAT coef;
    int8_t used[40];
} LongTermPrediction;

float *buf;
LongTermPrediction *ltp;
int i;
int samples_num;

void init_vars() {
    samples_num = 131072;  // ~512KB of float data (131072 * sizeof(float) ≈ 512KB)
    
    buf = (float*)aligned_alloc(32, sizeof(float) * (samples_num + 2048));
    if (!buf) exit(1);

    ltp = (LongTermPrediction*)aligned_alloc(32, sizeof(LongTermPrediction));
    if (!ltp) exit(1);

    ltp->present = 1;
    ltp->lag = 2048;
    ltp->coef_idx = 0;
    ltp->coef = 0.75f;
    for (int j = 0; j < 40; j++) {
        ltp->used[j] = j < 20 ? 1 : 0;
    }

    for (int j = 0; j < samples_num + 2048; j++) {
        buf[j] = (float)(j % 1000) / 1000.0f;
    }
}