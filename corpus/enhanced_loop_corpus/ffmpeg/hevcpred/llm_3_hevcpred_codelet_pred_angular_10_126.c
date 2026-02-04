#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mode;
extern int x;
extern  uint16_t *left;
extern  int inv_angle[];
extern uint16_t *ref_tmp;
extern int last;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access on left array
    // Modify access pattern on 'left' array to use a fixed stride instead of variable index,
    // simulating prefetching or vectorizable access. Here, we decouple the index calculation
    // and introduce a regular step in the source array access by aligning the computed index
    // to a base plus constant increment per iteration.

    if (last > -1) return;

    int base_index = -1 + ((last * inv_angle[mode - 11] + 128) >> 8);
    int step = inv_angle[mode - 11] >> 8; // approximated stride per x increment

    for (x = last; x <= -1; x++) {
        // Use strided access: base_index + (x - last) * step
        int src_idx = base_index + (x - last) * step;
        ref_tmp[x] = left[src_idx];
    }
}
