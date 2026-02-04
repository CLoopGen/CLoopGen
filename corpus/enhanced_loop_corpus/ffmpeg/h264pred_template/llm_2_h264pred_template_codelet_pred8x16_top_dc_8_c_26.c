#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reorganizing index calculation
    ptrdiff_t base = -stride;
    for (i = 0; i < 4; i++) {
        dc0 += src[base + i];
        dc1 += src[base + 4 + i];
    }
}
