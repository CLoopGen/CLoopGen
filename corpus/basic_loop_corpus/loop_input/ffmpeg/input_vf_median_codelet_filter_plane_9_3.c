#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int width;
uint16_t *ccoarse;
uint16_t *cfine;
int radiusV;
uint16_t *srcp;

void init_vars() {
    // Set parameters to control data size and loop behavior
    width = 1 << 20;  // Approximately 1 million elements for ~0.01 sec runtime
    radiusV = 3;      // Small positive value to ensure meaningful accumulation

    // Calculate required dimensions based on access patterns in the loop
    int shift = (9 + 1) / 2;  // shift = 5
    int coarse_stride = (1 << shift); // 32
    int fine_stride = (1 << shift);   // 32
    int max_fine_index = fine_stride * (width * ((1 << (shift)) - 1) + (width - 1)) + ((1 << shift) - 1);
    int max_coarse_index = coarse_stride * (width - 1) + ((1 << shift) - 1);

    // Allocate arrays with sufficient size to prevent out-of-bounds access
    cfine = (uint16_t*)calloc(max_fine_index + 1, sizeof(uint16_t));
    ccoarse = (uint16_t*)calloc(max_coarse_index + 1, sizeof(uint16_t));
    srcp = (uint16_t*)malloc(width * sizeof(uint16_t));

    // Initialize srcp with valid values within expected range
    for (int i = 0; i < width; i++) {
        // Ensure srcp[i] fits within 9+1=10 bits as implied by shifts and masks
        srcp[i] = rand() & 0x3FF;  // 10-bit random value
    }
}

// Provide weak definitions to allow linking with loop.o
__attribute__((weak)) void loop();

// Ensure symbols are defined