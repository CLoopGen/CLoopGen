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
    // Variant 1: Consecutive memory access (flatten strided access into contiguous)
    // Assume stride == 1 for consecutive layout; adjust indexing accordingly
    dc0 = 0;
    for (i = 0; i < 8; i++) {
        dc0 += src[-1 + i];
    }
}
