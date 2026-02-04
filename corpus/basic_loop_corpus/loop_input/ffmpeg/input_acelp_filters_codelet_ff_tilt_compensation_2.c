#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

float tilt;
float *samples;
int size;
int i;

void init_vars() {
    size = 32 * 1024 * 1024 / sizeof(float);  // ~128MB of data to target ~0.01s runtime
    samples = (float *)aligned_alloc(32, size * sizeof(float));
    if (!samples) {
        exit(1);
    }
    for (int j = 0; j < size; j++) {
        samples[j] = (float)(j % 1000) / 100.0f;
    }
    tilt = 0.5f;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}