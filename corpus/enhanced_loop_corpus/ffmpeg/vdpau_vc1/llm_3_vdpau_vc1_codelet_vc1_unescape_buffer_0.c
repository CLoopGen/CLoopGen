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
    // Variant 2: Consecutive Two-Element Lookahead with Combined Access Pattern
    uint8_t *local_src = src;
    int local_i = 0;
    for (local_i = 0; local_i < size; local_i++) {
        if (local_i >= 2 && local_i < size - 1 &&
            local_src[0] == 3 &&
            !local_src[-1] &&
            !local_src[-2] &&
            local_src[1] < 4) {
            dst[dsize++] = local_src[1];
            local_src += 2;  // Skip next element due to consumption
            local_i++;       // Compensate for combined access
        } else {
            dst[dsize++] = local_src[0];
            local_src++;
        }
    }
    // Update side-effects on global state
    src = local_src;
    i = local_i;
}
