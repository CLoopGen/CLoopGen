#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *src1;
float *src2;
int src2_len;
double *tab;
int tab_len;
int step;
int order0;
int steps;
int mask;
int i;
int j;

void init_vars() {
    // Define data sizes to achieve ~0.01 sec runtime on modern CPU
    // Empirical tuning: use ~16-32M iterations with moderate vector lengths
    tab_len = 256;
    src2_len = 1 << 18;  // 256K elements
    steps = 1 << 12;     // 4096 steps
    order0 = 64;
    step = 127;          // prime-like step for bit masking
    mask = 0;

    // Allocate arrays
    src1 = (float*)aligned_alloc(32, sizeof(float) * (order0 + steps));
    src2 = (float*)aligned_alloc(32, sizeof(float) * src2_len);
    tab = (double*)aligned_alloc(32, sizeof(double) * tab_len);

    // Initialize arrays to avoid NaN or extreme values affecting timing
    for (i = 0; i < order0 + steps; i++) {
        src1[i] = (float)(i & 511) * 0.01f;
    }
    for (i = 0; i < src2_len; i++) {
        src2[i] = 0.0f;
    }
    for (i = 0; i < tab_len; i++) {
        tab[i] = (double)(i + 1) * 0.001;
    }
}