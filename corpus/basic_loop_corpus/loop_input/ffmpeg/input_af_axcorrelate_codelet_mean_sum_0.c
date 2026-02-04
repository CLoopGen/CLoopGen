#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *in;
int size;
float mean_sum;

void init_vars() {
    size = 67108864; // Approximately 256MB of float data (67M elements * 4 bytes)
    in = (float *)aligned_alloc(32, size * sizeof(float));
    if (!in) {
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        in[i] = (float)(i % 1000) + 0.5f;
    }
    mean_sum = 0.0f;
}