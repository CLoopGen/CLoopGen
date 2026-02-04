#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t linesize1;
extern ptrdiff_t dlinesize;
extern int w0;
extern int h0;
extern unsigned int *cchange;
extern  uint16_t *i;
extern uint16_t *d;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2x
    // This variant processes two elements per iteration to promote consecutive, coalesced memory access
    // and improve cache utilization. Assumes w0 is even for simplicity.
    uint16_t *d_ptr = d;
    uint16_t *i_ptr = i;
    for (y = 0; y < h0; y++) {
        for (x = 0; x < w0 - 1; x += 2) {
            d_ptr[x]     = cchange[i_ptr[x]];
            d_ptr[x + 1] = cchange[i_ptr[x + 1]];
        }
        if (x < w0) {
            d_ptr[x] = cchange[i_ptr[x]];
        }
        d_ptr = (uint16_t *)((char *)d_ptr + dlinesize);
        i_ptr = (uint16_t *)((char *)i_ptr + linesize1);
    }
}
