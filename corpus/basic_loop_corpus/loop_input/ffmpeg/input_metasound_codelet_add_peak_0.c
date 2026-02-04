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
    width = 16777216;  // 16M elements -> processes 8M in loop (width/2), ~16MB float array
    ppc_gain = 1.5f;

    shape = (float*)aligned_alloc(32, width * sizeof(float));
    speech = (float*)aligned_alloc(32, width * sizeof(float));

    for (int j = 0; j < width; j++) {
        shape[j] = (float)(j % 100) + 1.0f;
        speech[j] = (float)(j % 50) + 0.5f;
    }
}