#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *lpc;
int i;
float *gamma_n;
float *gamma_d;
float lpc_n[10];
float lpc_d[10];

void init_vars() {
    lpc = (float*)aligned_alloc(32, 10 * sizeof(float));
    gamma_n = (float*)aligned_alloc(32, 10 * sizeof(float));
    gamma_d = (float*)aligned_alloc(32, 10 * sizeof(float));

    for (i = 0; i < 10; i++) {
        lpc[i] = 1.0f + i * 0.1f;
        gamma_n[i] = 0.5f + i * 0.05f;
        gamma_d[i] = 0.8f + i * 0.03f;
        lpc_n[i] = 0.0f;
        lpc_d[i] = 0.0f;
    }
}