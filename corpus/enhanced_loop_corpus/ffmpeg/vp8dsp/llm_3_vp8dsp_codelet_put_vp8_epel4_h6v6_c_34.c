#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern with Pointer Arithmetic
    // Replace indexed array access with strided pointer increments to simulate hardware-friendly access
    // Use pointers that step through src and tmp with fixed strides to emphasize memory bandwidth usage.

    uint8_t *src_p;
    uint8_t *tmp_p = tmp;

    for (y = 0; y < h + 6 - 1; y++) {
        src_p = src; // Base pointer for current row

        // Unroll x-loop and use direct pointer arithmetic for strided access
        tmp_p[0] = cm[(filter[2] * src_p[0] - filter[1] * src_p[-1] + filter[0] * src_p[-2] +
                       filter[3] * src_p[1] - filter[4] * src_p[2] + filter[5] * src_p[3] + 64) >> 7];
        tmp_p[1] = cm[(filter[2] * src_p[1] - filter[1] * src_p[0]  + filter[0] * src_p[-1] +
                       filter[3] * src_p[2] - filter[4] * src_p[3] + filter[5] * src_p[4] + 64) >> 7];
        tmp_p[2] = cm[(filter[2] * src_p[2] - filter[1] * src_p[1] + filter[0] * src_p[0] +
                       filter[3] * src_p[3] - filter[4] * src_p[4] + filter[5] * src_p[5] + 64) >> 7];
        tmp_p[3] = cm[(filter[2] * src_p[3] - filter[1] * src_p[2] + filter[0] * src_p[1] +
                       filter[3] * src_p[4] - filter[4] * src_p[5] + filter[5] * src_p[6] + 64) >> 7];

        tmp_p += 4;
        src += srcstride;
    }
}
