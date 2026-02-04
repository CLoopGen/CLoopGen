#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *output;
extern int p1;
extern int i;
extern uint32_t pix32;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_pix = pix32 + p1; // Remove potential write-after-write with external pix32
    for (i = 0; i < p1; i++) {
        volatile uint32_t *addr = (volatile uint32_t *)(output + 4*i);
        *addr = local_pix; // Eliminate address/data dependencies across iterations (fully unrolled semantic)
    }
    output += 4 * p1; // Update output pointer after loop (move WAW dependency out of loop)
}
