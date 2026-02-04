#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

#define TOTAL_BANDS 22
#define MAX_DATA_SIZE (128 * 1024 * 1024) // 128 MB target data size

uint8_t eband5ms[TOTAL_BANDS + 1];
float *g;
float *bandE;

void init_vars() {
    // Initialize eband5ms with increasing values to define band boundaries
    // Ensure that (eband5ms[i+1] - eband5ms[i]) << 2 scales appropriately
    for (int i = 0; i <= TOTAL_BANDS; i++) {
        eband5ms[i] = (uint8_t)(i * 4); // Spread out to allow sufficient band sizes
    }

    // Estimate total required size for g
    size_t total_size = 0;
    for (int i = 0; i < TOTAL_BANDS - 1; i++) {
        int band_size = (eband5ms[i + 1] - eband5ms[i]) << 2;
        total_size += band_size;
    }

    // Scale up if needed to reach desired memory footprint
    double scale_factor = sqrt((double)MAX_DATA_SIZE / (double)(total_size * sizeof(float)));
    if (scale_factor > 1.0) scale_factor = 1.0;
    int base_shift = 0;
    while (((1 << base_shift) < scale_factor * 4) && (base_shift < 4)) base_shift++;

    // Recompute eband5ms with scaled spacing if possible, but keep within uint8_t range
    if (base_shift > 0) {
        for (int i = 0; i <= TOTAL_BANDS; i++) {
            eband5ms[i] = (uint8_t)(i << base_shift);
        }
    }

    // Recalculate total size after potential scaling
    total_size = 0;
    for (int i = 0; i < TOTAL_BANDS - 1; i++) {
        int band_size = (eband5ms[i + 1] - eband5ms[i]) << 2;
        total_size += band_size;
    }

    // Allocate g and bandE
    g = (float*)aligned_alloc(32, total_size * sizeof(float));
    bandE = (float*)aligned_alloc(32, TOTAL_BANDS * sizeof(float));

    // Initialize bandE with non-zero values
    for (int i = 0; i < TOTAL_BANDS; i++) {
        bandE[i] = sinf((float)i) * 100.0f;
    }

    // Initialize g to zero to avoid undefined behavior
    memset(g, 0, total_size * sizeof(float));
}