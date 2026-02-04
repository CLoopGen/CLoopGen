#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern ptrdiff_t stride;
extern unsigned int k;
extern unsigned int j;
extern int rlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing destination pointer
    int16_t *d = dst;
    for (k = 0; k < rlen; k++) {
        d[k] = 0;
    }
    // Update shared state: j and dst reflect final position
    j = (j + rlen) % width;
    dst += (j == 0 ? rlen : (rlen + width - 1) / width * stride);
}
