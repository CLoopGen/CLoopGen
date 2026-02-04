#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int channels = 2;
int32_t *samples;
int stride = 4;
uint32_t bits[2] = {0};
int result = 24;
int i;
int j;

void init_vars() {
    size_t total_samples = 16777216; // ~64 MB of int32_t data (67,108,864 bytes)
    samples = aligned_alloc(32, total_samples * sizeof(int32_t));
    if (!samples) {
        exit(1);
    }
    for (size_t idx = 0; idx < total_samples; ++idx) {
        samples[idx] = rand() & 0xFFFFFFFF;
    }
}