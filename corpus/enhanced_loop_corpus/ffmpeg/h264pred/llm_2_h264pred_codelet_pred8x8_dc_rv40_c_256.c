#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern unsigned int dc0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Reorganize accesses to use consecutive indexing where possible by precomputing base pointers
    uint8_t *base1 = &src[-1];
    uint8_t *base2 = &src[-stride];
    uint8_t *base3 = &src[4 - stride];
    
    for (i = 0; i < 4; i++) {
        dc0 += base1[i * stride] + base2[i];
        dc0 += base3[i];
        dc0 += base1[(i + 4) * stride];
    }
}
