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
    // Variant 2: Strided Memory Access Pattern
    // Modify access pattern to use a fixed stride (e.g., every 2nd element in the scan order)
    // This simulates processing with gaps, which may improve cache behavior or align with specific data layouts.
    // We maintain the original logic but step through the loop with a stride of 2.

    int stride = 2;
    int adjusted_last = (last_non_zero - start_i) % stride == 0 ? last_non_zero : last_non_zero - 1;

    for (i = start_i; i <= adjusted_last; i += stride) {
        j = scantable[i];
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

    // Handle leftover element if any (when last_non_zero - start_i + 1 is odd)
    if ((last_non_zero - start_i + 1) % 2 == 1 && adjusted_last + 1 <= last_non_zero) {
        i = adjusted_last + 1;
        j = scantable[i];
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
