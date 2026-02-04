#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
uint16_t *ccoarse;
uint16_t *cfine;
int radiusV;
uint8_t *srcp;

void init_vars() {
    // Set parameters to control data size and ensure no out-of-bounds access
    const int bit_shift = (8 + 1) / 2; // == 4
    const int bin_size = 1 << bit_shift; // == 16
    const int max_fine_index = bin_size * bin_size; // 16*16 = 256 per coarse bin

    width = 1 << 20; // 1 million elements, approx. 1MB input, adjust for ~0.01s runtime
    radiusV = 5; // reasonable small value

    // Allocate srcp: each element is used as index via shifting and masking
    srcp = (uint8_t*)calloc(width, sizeof(uint8_t));
    // Initialize srcp with values that stay within valid index ranges
    for (int i = 0; i < width; i++) {
        srcp[i] = (uint8_t)(i % (bin_size * bin_size)); // ensures (srcp[i] >> 4) < 16 and (srcp[i] & 15) < 16
    }

    // ccoarse size: width * bin_size (each i maps to a bin of size bin_size)
    ccoarse = (uint16_t*)calloc(width * bin_size, sizeof(uint16_t));

    // cfine size: each coarse bin has bin_size * bin_size fine bins
    // total size = width * bin_size * bin_size
    cfine = (uint16_t*)calloc(width * bin_size * bin_size, sizeof(uint16_t));
}