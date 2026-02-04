#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y, x;
    for (y = 0; y < height + 3; y++) {
        // Eliminate loop-carried dependency by unrolling and reordering computations
        x = 0;
        if (width > 0) {
            tmp[0] = (filter[0] * src[-1] + filter[1] * src[0] + filter[2] * src[1] + filter[3] * src[2]) >> 4;
            for (x = 1; x < width; x += 2) {
                // Process two elements per iteration with no intra-loop dependency
                if (x + 1 < width) {
                    tmp[x]     = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 4;
                    tmp[x + 1] = (filter[0] * src[x]     + filter[1] * src[x + 1] + filter[2] * src[x + 2] + filter[3] * src[x + 3]) >> 4;
                } else {
                    tmp[x] = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 4;
                }
            }
        }
        src += srcstride;
        tmp += 64;
    }
}
