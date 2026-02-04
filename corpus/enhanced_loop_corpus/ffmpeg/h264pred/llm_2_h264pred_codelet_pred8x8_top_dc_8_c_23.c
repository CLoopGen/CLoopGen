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
    // Variant 1: Consecutive memory access pattern
    // Combine both original accesses into a single sequential pass
    uint8_t *base = src - stride;
    for (i = 0; i < 8; i++) {
        if (i < 4) {
            dc0 += base[i];
        } else {
            dc1 += base[i];
        }
    }
}
