#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

float *vec1;
float *vec2;
int n;
float result;
int x;

void init_vars() {
    n = 65536 * 4; // ~1MB of data per array (4 bytes per float)

    vec1 = (float*)aligned_alloc(32, n * sizeof(float));
    vec2 = (float*)aligned_alloc(32, n * sizeof(float));

    if (!vec1 || !vec2) {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        vec1[i] = 1.0f + (i % 100) * 0.01f;
        vec2[i] = 2.0f - (i % 100) * 0.01f;
    }

    result = 0.0f;
    x = 0;
}