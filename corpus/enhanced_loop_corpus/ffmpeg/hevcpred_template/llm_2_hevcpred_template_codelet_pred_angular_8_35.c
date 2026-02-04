#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mode;
extern int x;
extern  uint8_t *left;
extern  int inv_angle[];
extern uint8_t *ref_tmp;
extern int last;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computation to access ref_tmp in increasing order
    // This variant assumes that the original loop runs backward and transforms it into forward traversal
    // with adjusted indexing logic to preserve correctness.

    int start = last;
    if (start <= -1) {
        int base_offset = (inv_angle[mode - 11] * start + 128) >> 8;
        int step = inv_angle[mode - 11] >> 8;

        // Use consecutive access pattern for ref_tmp by iterating forward
        for (x = start; x <= -1; x++) {
            ref_tmp[x] = left[-1 + base_offset];
            base_offset += step;
        }
    }
}
