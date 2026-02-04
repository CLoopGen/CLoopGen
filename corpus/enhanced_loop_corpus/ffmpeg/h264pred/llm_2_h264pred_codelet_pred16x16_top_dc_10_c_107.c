#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering index calculation
    // Instead of negative stride access, access consecutive forward elements
    ptrdiff_t base = -stride;
    for (i = 0; i < 16; i++) {
        dc += src[base + i];
    }
}
