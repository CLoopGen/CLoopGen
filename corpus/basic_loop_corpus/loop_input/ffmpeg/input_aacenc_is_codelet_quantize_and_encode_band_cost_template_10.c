#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

float *in;
int size;
int i;
float cost;

void init_vars() {
    size = 64 * 1024 * 1024 / sizeof(float); // ~256 MB of data to ensure ~0.01s runtime on modern CPUs
    in = (float*)aligned_alloc(32, size * sizeof(float));
    if (!in) {
        exit(1);
    }
    for (int j = 0; j < size; j++) {
        in[j] = 1.0f + (j % 100) / 100.0f;
    }
    i = 0;
    cost = 0.0f;
}