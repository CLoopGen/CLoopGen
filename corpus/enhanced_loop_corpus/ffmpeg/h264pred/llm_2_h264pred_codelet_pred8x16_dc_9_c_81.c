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
    // Variant 1: Consecutive memory access by reordering and simplifying strides
    ptrdiff_t s = stride;
    for (i = 0; i < 4; i++) {
        dc0 += src[i * s - 1] + src[i - s];
        dc1 += src[i + 4 - s];
        dc2 += src[i * s + 4*s - 1];
        dc3 += src[i * s + 8*s - 1];
        dc4 += src[i * s + 12*s - 1];
    }
}
