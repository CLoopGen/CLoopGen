#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  int *qmat;
extern  uint8_t *scantable;
extern unsigned int threshold1;
extern unsigned int threshold2;
extern int start_i;
extern int last_non_zero;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Memory Access
    // Instead of accessing each element sequentially in reverse, access every other element first,
    // then fill in the gaps (tiled or strided pattern). This changes spatial locality.
    // We perform two passes: first on odd indices, then even, both in descending order.
    // This simulates a stride-2 access pattern to increase cache line utilization diversity.

    // First pass: odd indices
    for (i = 63; i >= start_i; i -= 2) {
        const int j = scantable[i];
        int level = block[j] * qmat[j];
        if (((unsigned int)(level + threshold1)) > threshold2) {
            last_non_zero = i;
            return;
        }
    }

    // Second pass: even indices (descending from 62)
    for (i = 62; i >= start_i; i -= 2) {
        const int j = scantable[i];
        int level = block[j] * qmat[j];
        if (((unsigned int)(level + threshold1)) > threshold2) {
            last_non_zero = i;
            break;
        }
    }
}
