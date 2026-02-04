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
    const uint16_t* base_src = src + y * srcstride;
    int16_t* base_tmp = tmp + y * 64;
    for (x = 0; x < width; x++) {
        const uint16_t* p = base_src + x;
        tmp[x] = ((int16_t)filter[0] * p[-3] + (int16_t)filter[1] * p[-2] + 
                  (int16_t)filter[2] * p[-1] + (int16_t)filter[3] * p[0] + 
                  (int16_t)filter[4] * p[1] + (int16_t)filter[5] * p[2] + 
                  (int16_t)filter[6] * p[3] + (int16_t)filter[7] * p[4]) >> 2;
    }
}
}
