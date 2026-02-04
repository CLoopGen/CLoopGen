#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern uint16_t *pix;
extern  int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled in a linear fashion
    uint16_t *p = pix;
    int32_t *b = block;
    for (i = 0; i < 4; i++) {
        uint16_t v = p[-1];
        v += b[0]; p[0] = v;
        v += b[1]; p[1] = v;
        v += b[2]; p[2] = v;
        v += b[3]; p[3] = v;
        p += stride;
        b += 4;
    }
}
