#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024 / sizeof(uint16_t))

int16_t *tmp;
uint16_t *src;
int tmpStride;
int srcStride;
int h;
int pad;
int i;

void init_vars() {
    // Allocate large buffers to ensure loop takes ~0.01 seconds
    src = aligned_alloc(32, TOTAL_ELEMENTS * sizeof(uint16_t));
    tmp = aligned_alloc(32, TOTAL_ELEMENTS * sizeof(int16_t));

    if (!src || !tmp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data
    for (size_t idx = 0; idx < TOTAL_ELEMENTS; idx++) {
        src[idx] = (uint16_t)(idx % 1000);
    }

    // Set strides (in elements, not bytes)
    tmpStride = 64;
    srcStride = 64;

    // Set loop count: choose h so that we don't go out of bounds
    // We access src[-2] to src[3], so need at least 5 elements per row
    // Also need to ensure we don't stride past allocated memory
    size_t max_rows = TOTAL_ELEMENTS / srcStride;
    h = (int)(max_rows * 0.8); // Use 80% of available rows for safety

    // Ensure h+5 doesn't exceed safe bound
    if (h + 5 > (int)max_rows) {
        h = (int)max_rows - 5;
    }

    // Set padding value
    pad = 10;

    // Adjust tmp and src pointers to valid starting positions
    // Need at least 2 elements before start due to src[-2]
    src += 2;
}

// External symbols must be defined at file scope
int16_t *tmp = NULL;
uint16_t *src = NULL;
int tmpStride = 0;
int srcStride = 0;
int h = 0;
int pad = 0;
int i = 0;