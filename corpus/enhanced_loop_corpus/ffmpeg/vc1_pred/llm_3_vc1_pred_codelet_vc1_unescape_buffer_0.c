#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive dual-element look-ahead access pattern with combined condition evaluation
    uint8_t *local_src = src;
    int local_i = 0;
    int local_dsize = dsize;

    for (; local_i < size; local_i++, local_src++) {
        // Prefetch and batch check conditions over a window of three elements where possible
        if (local_i >= 2 && (local_i + 1) < size &&
            local_src[0] == 3 && 
            !local_src[-1] && 
            !local_src[-2] && 
            local_src[1] < 4) {
            // Insert lookahead value
            dst[local_dsize++] = local_src[1];
            // Skip next iteration by manually advancing index and pointer
            local_i++;
            local_src++;
        } else {
            dst[local_dsize++] = *local_src;
        }
    }

    // Update side-effects to extern variables
    i = local_i;
    src = local_src;
    dsize = local_dsize;
}
