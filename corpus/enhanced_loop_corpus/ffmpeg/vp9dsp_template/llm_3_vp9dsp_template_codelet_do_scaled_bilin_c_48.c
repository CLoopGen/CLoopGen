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
    // Variant 2: Strided Memory Access with Step-2 Access Pattern
    // Modify access to src with a fixed stride and unroll by 2 to create strided access pattern
    // This changes data access locality and increases stride in source buffer usage
    int local_imx = imx;
    int local_ioff = ioff;
    int limit = w - 1;
    for (x = 0; x < limit; x += 2) {
        // Unrolled iteration with strided access
        tmp_ptr[x] = (src[local_ioff] + ((local_imx * (src[local_ioff + 1] - src[local_ioff]) + 8) >> 4));
        int next_ioff1 = local_ioff + (local_imx >> 4);
        local_imx = (local_imx + dx) & 15;

        tmp_ptr[x+1] = (src[next_ioff1] + ((local_imx * (src[next_ioff1 + 1] - src[next_ioff1]) + 8) >> 4));
        int next_ioff2 = next_ioff1 + (local_imx >> 4);
        local_imx = (local_imx + dx) & 15;
        local_ioff = next_ioff2;
    }
    // Handle remaining element if w is odd
    if (x < w) {
        tmp_ptr[x] = (src[local_ioff] + ((local_imx * (src[local_ioff + 1] - src[local_ioff]) + 8) >> 4));
        local_imx = (local_imx + dx) & 15;
        local_ioff += (local_imx >> 4);
    }
    imx = local_imx;
    ioff = local_ioff;
}
