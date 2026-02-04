#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height + 7; y++) {
    for (x = 0; x < width; x += 2) { // Strided access with step 2
        int src_offset = y * srcstride + x;
        // Process two elements at once to maintain coverage
        tmp[x] = (filter[0] * src[src_offset - 3] + filter[1] * src[src_offset - 2] +
                  filter[2] * src[src_offset - 1] + filter[3] * src[src_offset] +
                  filter[4] * src[src_offset + 1] + filter[5] * src[src_offset + 2] +
                  filter[6] * src[src_offset + 3] + filter[7] * src[src_offset + 4]) >> 4;

        if (x + 1 < width) {
            tmp[x + 1] = (filter[0] * src[src_offset - 2] + filter[1] * src[src_offset - 1] +
                          filter[2] * src[src_offset]     + filter[3] * src[src_offset + 1] +
                          filter[4] * src[src_offset + 2] + filter[5] * src[src_offset + 3] +
                          filter[6] * src[src_offset + 4] + filter[7] * src[src_offset + 5]) >> 4;
        }
    }
    tmp += 64;
}
}
