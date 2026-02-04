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
    const uint16_t* src_base = src;
    for (x = 0; x < width; x += 4) {
        tmp[x + 0] = (filter[0] * src_base[x + 0 - 3] + filter[1] * src_base[x + 0 - 2] + 
                      filter[2] * src_base[x + 0 - 1] + filter[3] * src_base[x + 0] + 
                      filter[4] * src_base[x + 0 + 1] + filter[5] * src_base[x + 0 + 2] + 
                      filter[6] * src_base[x + 0 + 3] + filter[7] * src_base[x + 0 + 4]) >> 4;
        tmp[x + 1] = (filter[0] * src_base[x + 1 - 3] + filter[1] * src_base[x + 1 - 2] + 
                      filter[2] * src_base[x + 1 - 1] + filter[3] * src_base[x + 1] + 
                      filter[4] * src_base[x + 1 + 1] + filter[5] * src_base[x + 1 + 2] + 
                      filter[6] * src_base[x + 1 + 3] + filter[7] * src_base[x + 1 + 4]) >> 4;
        tmp[x + 2] = (filter[0] * src_base[x + 2 - 3] + filter[1] * src_base[x + 2 - 2] + 
                      filter[2] * src_base[x + 2 - 1] + filter[3] * src_base[x + 2] + 
                      filter[4] * src_base[x + 2 + 1] + filter[5] * src_base[x + 2 + 2] + 
                      filter[6] * src_base[x + 2 + 3] + filter[7] * src_base[x + 2 + 4]) >> 4;
        tmp[x + 3] = (filter[0] * src_base[x + 3 - 3] + filter[1] * src_base[x + 3 - 2] + 
                      filter[2] * src_base[x + 3 - 1] + filter[3] * src_base[x + 3] + 
                      filter[4] * src_base[x + 3 + 1] + filter[5] * src_base[x + 3 + 2] + 
                      filter[6] * src_base[x + 3 + 3] + filter[7] * src_base[x + 3 + 4]) >> 4;
    }
    src += srcstride;
    tmp += 64;
}
}
