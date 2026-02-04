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
    int offset = y * srcstride;
    for (x = 0; x < width; x++) {
        int idx = offset + x;
        tmp[x] = (filter[0] * src[idx - 3] + filter[1] * src[idx - 2] + 
                  filter[2] * src[idx - 1] + filter[3] * src[idx] + 
                  filter[4] * src[idx + 1] + filter[5] * src[idx + 2] + 
                  filter[6] * src[idx + 3] + filter[7] * src[idx + 4]) >> 4;
    }
    tmp += 64;
}
}
