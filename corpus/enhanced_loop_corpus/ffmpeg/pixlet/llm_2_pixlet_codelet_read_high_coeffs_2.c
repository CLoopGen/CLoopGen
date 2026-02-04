#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern ptrdiff_t stride;
extern unsigned int rlen;
extern unsigned int j;
extern unsigned int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing destination pointer
    int16_t *d = dst;
    for (k = 0; k < rlen; k++) {
        d[k] = 0;
    }
    // Update shared state after the loop
    j = (j + rlen) % width;
    dst += (j == 0) ? (rlen / width) * stride : (rlen / width) * stride + (rlen % width > (width - (j + rlen) % width) ? 1 : 0);
}
