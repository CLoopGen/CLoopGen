#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height + 3; y++) {
        int8_t f0 = filter[0], f1 = filter[1], f2 = filter[2], f3 = filter[3]; // Remove repeated memory access: eliminate potential WAR/WAW on filter
        uint8_t* local_src = src;
        int16_t* local_tmp = tmp;
        // Break loop-carried dependency on tmp by unrolling and processing non-overlapping indices
        x = 0;
        for (; x < width - 3; x += 4) {
            local_tmp[x]   = (f0 * local_src[x - 1] + f1 * local_src[x] + f2 * local_src[x + 1] + f3 * local_src[x + 2]) >> 8;
            local_tmp[x+1] = (f0 * local_src[x]     + f1 * local_src[x+1] + f2 * local_src[x+2] + f3 * local_src[x+3]) >> 8;
            local_tmp[x+2] = (f0 * local_src[x+1]   + f1 * local_src[x+2] + f2 * local_src[x+3] + f3 * local_src[x+4]) >> 8;
            local_tmp[x+3] = (f0 * local_src[x+2]   + f1 * local_src[x+3] + f2 * local_src[x+4] + f3 * local_src[x+5]) >> 8;
        }
        // Handle remainder
        for (; x < width; x++) {
            local_tmp[x] = (f0 * local_src[x - 1] + f1 * local_src[x] + f2 * local_src[x + 1] + f3 * local_src[x + 2]) >> 8;
        }
        src += srcstride;
        tmp += 64;
    }
}
