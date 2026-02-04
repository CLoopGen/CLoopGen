#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *dst;
uint8_t *src2;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

#define DATA_SIZE (64 * 1024 * 1024)  // ~64MB to ensure ~0.01s runtime on modern CPU
#define TMP_EXTRA 11  // Need tmp[-2] to tmp[10], so we need at least 13 extra elements before and after
#define STRIDE_DEFAULT 1

void init_vars() {
    // Allocate cm as a lookup table for clamping, size 256*4 to be safe
    cm = aligned_alloc(32, 1024 * sizeof(uint8_t));
    for (int idx = 0; idx < 1024; idx++) {
        cm[idx] = (uint8_t)((idx > 255) ? 255 : (idx < 0) ? 0 : idx);
    }

    // Set strides
    dstStride = STRIDE_DEFAULT;
    srcStride = STRIDE_DEFAULT;

    // Allocate tmp with sufficient padding to allow indexing from -2 to 10 beyond the main segment
    int total_tmp_elements = (DATA_SIZE / 8) + TMP_EXTRA;
    tmp = aligned_alloc(32, total_tmp_elements * sizeof(int16_t));
    
    // Initialize tmp with dummy data
    for (int idx = 0; idx < total_tmp_elements; idx++) {
        tmp[idx] = (int16_t)(rand() % 512 - 256);  // Random values in reasonable range
    }

    // Adjust base pointer so that valid access starts after -2 offset
    // So user accesses start at tmp + 2, ensuring tmp[-2] is valid
    tmp += 2;

    // Now allocate dst and src2 arrays
    dst = aligned_alloc(32, DATA_SIZE * sizeof(uint8_t));
    src2 = aligned_alloc(32, DATA_SIZE * sizeof(uint8_t));

    // Initialize src2 with random data
    for (int idx = 0; idx < DATA_SIZE; idx++) {
        src2[idx] = (uint8_t)(rand() % 256);
        dst[idx] = 0;  // Clear output
    }

    // Set loop count: each iteration processes 8 rows (due to *8 stride in tmp indexing)
    w = DATA_SIZE / 8;

    // Ensure bounds: after w iterations, max tmp index used is (7 + 2) => tmp[9*8] -> tmp[72]
    // Our tmp has size: (DATA_SIZE/8 + TMP_EXTRA), indexed by units of 8 -> max index offset 10 allowed
    // So we must ensure: (w-1) + 10 <= total_tmp_elements - 2 (after adjustment)
    // Thus: w <= total_tmp_elements - 12 = (DATA_SIZE/8 + TMP_EXTRA) - 12 = DATA_SIZE/8 - 1
    // So cap w accordingly:
    if (w >= (total_tmp_elements - 12)) {
        w = total_tmp_elements - 12;
    }
}