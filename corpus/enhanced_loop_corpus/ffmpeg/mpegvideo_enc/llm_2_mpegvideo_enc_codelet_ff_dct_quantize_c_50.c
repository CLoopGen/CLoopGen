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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing `scantable[i]` sequentially, we access it with a fixed stride (e.g., 2)
    // and handle possible out-of-bounds by ensuring i stays within valid range.
    int stride = 2;
    int end_i = last_non_zero;
    for (i = start_i; i <= end_i; i += stride) {
        if (i > last_non_zero) break;
        j = scantable[i];
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
    // Handle remaining elements if stride causes skip
    for (i = start_i + 1; i <= end_i; i += 2) {
        if ((start_i & 1) != (i & 1)) continue; // Only process odd-start offsets if needed
        j = scantable[i];
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
