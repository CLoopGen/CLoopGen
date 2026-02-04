#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing a base pointer and accessing consecutive elements
    uint8_t *base = &src[-1];
    for (i = 0; i < 16; i++) {
        dc += base[i * stride];
    }
}
