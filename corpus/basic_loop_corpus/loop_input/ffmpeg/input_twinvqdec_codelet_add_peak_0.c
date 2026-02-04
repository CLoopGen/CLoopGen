#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
float *shape;
float ppc_gain;
float *speech;
int i;

void init_vars() {
    width = 1 << 20;  // 1MB of float data (2^20 floats = ~4MB total for two arrays)
    ppc_gain = 1.5f;

    speech = (float *)aligned_alloc(32, width * sizeof(float));
    shape = (float *)aligned_alloc(32, width * sizeof(float));

    for (int j = 0; j < width; j++) {
        speech[j] = (float)(j % 100) / 10.0f;
        shape[j] = 1.0f;
    }
}