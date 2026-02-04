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
    // Reduce arithmetic operations and simplify control flow
    // Eliminate redundant bounds checks where possible via early exit logic
    uint8_t* local_src = src;
    int local_dsize = dsize;
    
    for (i = 0; i < size; i++) {
        uint8_t val = *local_src;
        if (val == 3 && i >= 2 && local_src[-1] == 0 && local_src[-2] == 0 &&
            i < size - 1 && local_src[1] < 4) {
            dst[local_dsize++] = local_src[1];
            local_src += 2; // Skip two positions: current and next
            i++; // Compensate for skipped input
        } else {
            dst[local_dsize++] = val;
            local_src++;
        }
    }
    // Update side effects
    src = local_src;
    dsize = local_dsize;
}
