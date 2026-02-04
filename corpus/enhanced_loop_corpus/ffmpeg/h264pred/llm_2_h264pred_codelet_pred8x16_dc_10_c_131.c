#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern int dc3;
extern int dc4;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Reorganize memory accesses to be consecutive by precomputing base pointers
    uint16_t *src_base0 = src - 1;
    uint16_t *src_base1 = src;
    uint16_t *src_base2 = src + 4;
    
    for (i = 0; i < 4; i++) {
        dc0 += src_base0[i * stride] + src_base1[i];
        dc1 += src_base2[i];
        dc2 += src_base0[(i + 4) * stride];
        dc3 += src_base0[(i + 8) * stride];
        dc4 += src_base0[(i + 12) * stride];
    }
}
