#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc2;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base pointers and accessing elements consecutively
    uint8_t *base1 = &src[-1];
    uint8_t *base2 = &src[-1 + 4 * stride];
    for (i = 0; i < 4; i++) {
        dc0 += base1[i * stride];
        dc2 += base2[i * stride];
    }
}
