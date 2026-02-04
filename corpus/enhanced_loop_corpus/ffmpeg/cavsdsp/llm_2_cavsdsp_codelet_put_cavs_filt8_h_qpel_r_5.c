#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Local Blocking
    // Instead of strided access, we prefetch a block of src data into a local array to promote consecutive access.
    uint8_t block[16]; // Local buffer to hold a block of src data for consecutive processing
    for (i = 0; i < h; i++) {
        // Load a block of src data centered around the current position
        for (int j = 0; j < 16; j++) {
            block[j] = src[j - 2];
        }
        // Now compute using consecutive accesses in block[]
        dst[0] = cm[((0 * block[0] + -7 * block[1] + 42 * block[2] + 96 * block[3] + -2 * block[4] + -1 * block[5]) + 64) >> 7];
        dst[1] = cm[((0 * block[1] + -7 * block[2] + 42 * block[3] + 96 * block[4] + -2 * block[5] + -1 * block[6]) + 64) >> 7];
        dst[2] = cm[((0 * block[2] + -7 * block[3] + 42 * block[4] + 96 * block[5] + -2 * block[6] + -1 * block[7]) + 64) >> 7];
        dst[3] = cm[((0 * block[3] + -7 * block[4] + 42 * block[5] + 96 * block[6] + -2 * block[7] + -1 * block[8]) + 64) >> 7];
        dst[4] = cm[((0 * block[4] + -7 * block[5] + 42 * block[6] + 96 * block[7] + -2 * block[8] + -1 * block[9]) + 64) >> 7];
        dst[5] = cm[((0 * block[5] + -7 * block[6] + 42 * block[7] + 96 * block[8] + -2 * block[9] + -1 * block[10]) + 64) >> 7];
        dst[6] = cm[((0 * block[6] + -7 * block[7] + 42 * block[8] + 96 * block[9] + -2 * block[10] + -1 * block[11]) + 64) >> 7];
        dst[7] = cm[((0 * block[7] + -7 * block[8] + 42 * block[9] + 96 * block[10] + -2 * block[11] + -1 * block[12]) + 64) >> 7];
        dst += dstStride;
        src += srcStride;
    }
}
