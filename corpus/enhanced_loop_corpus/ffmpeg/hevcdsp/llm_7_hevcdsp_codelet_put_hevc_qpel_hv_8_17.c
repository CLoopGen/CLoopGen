#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height + 7; y++) {
        #pragma unroll
        for (x = 0; x < width; x += 4) {
            // Unroll and remove WAW dependencies by writing to non-overlapping indices
            tmp[x]     = (filter[0] * src[x - 3] + filter[1] * src[x - 2] + filter[2] * src[x - 1] + 
                          filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2] + 
                          filter[6] * src[x + 3] + filter[7] * src[x + 4]) >> 0;
            tmp[x + 1] = (filter[0] * src[x - 2] + filter[1] * src[x - 1] + filter[2] * src[x] + 
                          filter[3] * src[x + 1] + filter[4] * src[x + 2] + filter[5] * src[x + 3] + 
                          filter[6] * src[x + 4] + filter[7] * src[x + 5]) >> 0;
            tmp[x + 2] = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + 
                          filter[3] * src[x + 2] + filter[4] * src[x + 3] + filter[5] * src[x + 4] + 
                          filter[6] * src[x + 5] + filter[7] * src[x + 6]) >> 0;
            tmp[x + 3] = (filter[0] * src[x] + filter[1] * src[x + 1] + filter[2] * src[x + 2] + 
                          filter[3] * src[x + 3] + filter[4] * src[x + 4] + filter[5] * src[x + 5] + 
                          filter[6] * src[x + 6] + filter[7] * src[x + 7]) >> 0;
        }
        src += srcstride;
        tmp += 64;
    }
}
