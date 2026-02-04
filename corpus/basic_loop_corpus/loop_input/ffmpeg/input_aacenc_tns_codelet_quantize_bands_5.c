#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int *out;
float *in;
float *scaled;
int size;
int is_signed;
int maxval;
float Q34;
float rounding;
int i;

void init_vars() {
    size = 64 * 1024 * 1024 / sizeof(float);  // ~256MB of float data to target ~0.01s on modern CPU
    in = (float *)aligned_alloc(32, size * sizeof(float));
    scaled = (float *)aligned_alloc(32, size * sizeof(float));
    out = (int *)aligned_alloc(32, size * sizeof(int));

    is_signed = 1;
    maxval = 255;
    Q34 = 1.5f;
    rounding = 0.5f;

    for (i = 0; i < size; i++) {
        in[i] = (rand() % 2 ? -1.0f : 1.0f) * (rand() / (float)RAND_MAX);
        scaled[i] = (rand() / (float)RAND_MAX) * 100.0f;
    }
}