#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int dx;
extern uint8_t *tmp_ptr;
extern  uint8_t *src;
extern int x;
extern int imx;
extern int ioff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Prefetching Pattern
    // We modify the access pattern by precomputing a sequence of ioff values to enable more sequential-like behavior.
    int local_imx = imx;
    int local_ioff = ioff;
    for (x = 0; x < w; x++) {
        int next_ioff = local_ioff + (local_imx >> 4);
        tmp_ptr[x] = (src[local_ioff] + ((local_imx * (src[local_ioff + 1] - src[local_ioff]) + 8) >> 4));
        local_imx = (local_imx + dx) & 15;
        local_ioff = next_ioff;
    }
    imx = local_imx;
    ioff = local_ioff;
}
