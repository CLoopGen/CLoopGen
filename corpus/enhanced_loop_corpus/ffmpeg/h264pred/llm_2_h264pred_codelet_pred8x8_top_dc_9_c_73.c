#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint16_t *src1 = src - stride;
    for (i = 0; i < 4; i++) {
        dc0 += *(src1 + i);
        dc1 += *(src1 + 4 + i);
    }
}
