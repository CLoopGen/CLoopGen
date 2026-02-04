#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *out;
float fir_coef[31];
int i;
int j;
float data[110];

void init_vars() {
    out = (float*)aligned_alloc(32, 80 * sizeof(float));
    for (int idx = 0; idx < 80; ++idx) {
        out[idx] = 0.0f;
    }
    for (int idx = 0; idx < 31; ++idx) {
        fir_coef[idx] = 1.0f / (idx + 1);
    }
    for (int idx = 0; idx < 110; ++idx) {
        data[idx] = (float)(rand() % 100) / 10.0f;
    }
}