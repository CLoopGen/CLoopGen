#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float *out;
float *in1;
float *in2;
float *window;
int len;
int i;

void init_vars() {
    len = 8 * 1024 * 1024; // Approximately 32 MB of float data (8M elements)

    out = (float*)aligned_alloc(32, len * sizeof(float));
    in1 = (float*)aligned_alloc(32, len * sizeof(float));
    in2 = (float*)aligned_alloc(32, len * sizeof(float));
    window = (float*)aligned_alloc(32, len * sizeof(float));

    for (int j = 0; j < len; j++) {
        in1[j] = (float)(rand() % 100) / 100.0f;
        in2[j] = (float)(rand() % 100) / 100.0f;
        window[j] = (float)(rand() % 100) / 100.0f;
    }

    i = 0;
}