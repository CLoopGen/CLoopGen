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
    // Variant 1: Consecutive memory access with array indexing using pointer arithmetic unrolled by 2
    for (y = 0; y < height + 3; y++) {
        uint8_t *src_p = src;
        int16_t *tmp_p = tmp;
        for (x = 0; x < width - 1; x += 2) {
            // Unrolling two iterations and accessing consecutive elements to improve spatial locality
            tmp_p[x]   = (filter[0] * src_p[x - 1] + filter[1] * src_p[x] + filter[2] * src_p[x + 1] + filter[3] * src_p[x + 2]) >> 0;
            tmp_p[x+1] = (filter[0] * src_p[x]     + filter[1] * src_p[x+1] + filter[2] * src_p[x + 2] + filter[3] * src_p[x + 3]) >> 0;
        }
        // Handle remaining element if width is odd
        if (x < width) {
            tmp_p[x] = (filter[0] * src_p[x - 1] + filter[1] * src_p[x] + filter[2] * src_p[x + 1] + filter[3] * src_p[x + 2]) >> 0;
        }
        src += srcstride;
        tmp += 64;
    }
}
