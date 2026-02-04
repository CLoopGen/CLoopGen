#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int i;
extern int j;
extern int level;
extern int last_non_zero;
extern int start_i;
extern  int *qmat;
extern  uint8_t *scantable;
extern int bias;
extern int max;
extern unsigned int threshold1;
extern unsigned int threshold2;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive Memory Access via Local Reordering Buffer
    // Precompute the sequence of `j` indices from `scantable` into a local array to enable consecutive access
    // This improves cache locality by decoupling indirect memory access from computation
    #define MAX_BLOCK_SIZE 64
    int temp_j[MAX_BLOCK_SIZE];
    int count = 0;
    int k;

    // Prefetch all j values in order
    for (k = start_i; k <= last_non_zero && count < MAX_BLOCK_SIZE; k++) {
        temp_j[count++] = scantable[k];
    }

    // Now iterate over the prefetched indices with consecutive access pattern
    for (k = 0; k < count; k++) {
        j = temp_j[k];
        level = block[j] * qmat[j];
        if (((unsigned int)(level + threshold1)) > threshold2) {
            if (level > 0) {
                level = (bias + level) >> 21;
                block[j] = level;
            } else {
                level = (bias - level) >> 21;
                block[j] = -level;
            }
            max |= level;
        } else {
            block[j] = 0;
        }
    }
}
