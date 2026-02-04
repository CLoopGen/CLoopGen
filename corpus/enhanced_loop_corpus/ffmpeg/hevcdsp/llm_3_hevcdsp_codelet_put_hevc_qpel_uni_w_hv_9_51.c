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
    for (x = 0; x < width; x++) {
        int idxs[] = {x - 3, x - 2, x - 1, x, x + 1, x + 2, x + 3, x + 4};
        tmp[x] = (filter[0] * src_base[idxs[0]] + filter[1] * src_base[idxs[1]] + 
                  filter[2] * src_base[idxs[2]] + filter[3] * src_base[idxs[3]] + 
                  filter[4] * src_base[idxs[4]] + filter[5] * src_base[idxs[5]] + 
                  filter[6] * src_base[idxs[6]] + filter[7] * src_base[idxs[7]]) >> 1;
    }
    src += srcstride;
    tmp += 64;
}
}
