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
    for (x = 0; x < width; x += 2) { // Strided access: process two elements per iteration
        int base_src = (y * srcstride) + x;
        int base_tmp = x;

        // First element
        tmp[base_tmp] = (filter[0] * src[base_src - 3] + filter[1] * src[base_src - 2] + 
                         filter[2] * src[base_src - 1] + filter[3] * src[base_src] + 
                         filter[4] * src[base_src + 1] + filter[5] * src[base_src + 2] + 
                         filter[6] * src[base_src + 3] + filter[7] * src[base_src + 4]) >> 1;

        // Second element, if within bounds
        if (x + 1 < width) {
            tmp[base_tmp + 1] = (filter[0] * src[base_src - 2] + filter[1] * src[base_src - 1] + 
                                 filter[2] * src[base_src]     + filter[3] * src[base_src + 1] + 
                                 filter[4] * src[base_src + 2] + filter[5] * src[base_src + 3] + 
                                 filter[6] * src[base_src + 4] + filter[7] * src[base_src + 5]) >> 1;
        }
    }
    tmp += 64;
}
}
