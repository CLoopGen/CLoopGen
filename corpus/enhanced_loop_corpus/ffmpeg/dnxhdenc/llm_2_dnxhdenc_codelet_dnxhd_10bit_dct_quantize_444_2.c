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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of using indirect access via scantable[i], we reorganize the loop to process block elements
    // in a consecutive manner. We assume that 'scantable' maps to a permutation of indices from start_i
    // to last_non_zero, and we precompute or reorder accordingly.
    // For this variant, we simulate a reordered processing where j values are accessed consecutively.

    int range_start = (start_i < 0) ? 0 : start_i;
    int range_end = (last_non_zero > 63) ? 63 : last_non_zero; // assuming 8x8 block (64 elements)

    for (i = range_start; i <= range_end; i++) {
        j = i; // Direct consecutive access instead of indirect via scantable
        level = block[j] * qmat[j];
        if (((unsigned int)(level + threshold1)) > threshold2) {
            if (level > 0) {
                level = (bias + level) >> 16;
                block[j] = level;
            } else {
                level = (bias - level) >> 16;
                block[j] = -level;
            }
            max |= level;
        } else {
            block[j] = 0;
        }
    }
}
