#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * (1 << 20) / sizeof(float))

float *out;
float *in;
int n = ARRAY_SIZE;
int i;
float scalefactor;

void init_vars() {
    out = (float*)aligned_alloc(32, ARRAY_SIZE * sizeof(float));
    in = (float*)aligned_alloc(32, ARRAY_SIZE * sizeof(float));
    scalefactor = 1.5f;

    for (int j = 0; j < ARRAY_SIZE; j++) {
        in[j] = (float)(j % 1000) + 1.0f;
        out[j] = 0.0f;
    }
}