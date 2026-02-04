#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int num_taps = 1048576; // ~1M elements, approx 4MB float array
float scale = 2.5f;
int dc_norm = 1;
int i;
float *h;
float sum = 1000.0f;

void init_vars() {
    h = (float*)aligned_alloc(32, num_taps * sizeof(float));
    if (!h) {
        exit(1);
    }
    for (int idx = 0; idx < num_taps; idx++) {
        h[idx] = 1.0f + (idx % 256) * 0.01f;
    }
}