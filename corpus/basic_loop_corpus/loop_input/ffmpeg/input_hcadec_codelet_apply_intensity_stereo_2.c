#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int band_count;
float ratio_l;
float ratio_r;
float *c1;
float *c2;

static float *c1_buffer;
static float *c2_buffer;

void init_vars() {
    // Set ratios to typical values
    ratio_l = 0.8f;
    ratio_r = 1.2f;

    // Determine data size for ~0.01s runtime: aim for ~64M elements based on typical performance
    size_t num_elements = 67108864; // 64 * 1024 * 1024

    // Allocate memory for c1 and c2 arrays
    c1_buffer = (float*)aligned_alloc(32, num_elements * sizeof(float));
    c2_buffer = (float*)aligned_alloc(32, num_elements * sizeof(float));

    if (!c1_buffer || !c2_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize c1 with sample data
    for (size_t i = 0; i < num_elements; i++) {
        c1_buffer[i] = (float)(i % 1000) * 0.01f;
    }

    // Set pointers and bounds
    c1 = c1_buffer;
    c2 = c2_buffer;
    band_count = (unsigned int)num_elements;
}