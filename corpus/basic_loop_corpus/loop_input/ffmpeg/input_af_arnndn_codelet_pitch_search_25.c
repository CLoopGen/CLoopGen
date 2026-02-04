#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *x_lp;
int len;
float x_lp4[960];

void init_vars() {
    len = 960 * 2; // Ensure j < len >> 2 => j < 480, so we need x_lp to have at least 2*j+1 = 2*479*2 = 958*2? -> max index 2*j with j=479 -> 958
    x_lp = (float*)aligned_alloc(32, len * sizeof(float));
    for (int i = 0; i < len; i++) {
        x_lp[i] = (float)(i * 2 + 1);
    }
    for (int i = 0; i < 960; i++) {
        x_lp4[i] = 0.0f;
    }
}