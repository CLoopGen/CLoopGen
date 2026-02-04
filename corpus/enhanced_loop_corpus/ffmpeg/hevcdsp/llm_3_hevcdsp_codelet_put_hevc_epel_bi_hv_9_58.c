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
for (y = 0; y < height + 3; y++) {
    for (x = 0; x < width; x++) {
        ptrdiff_t idx = x;
        tmp[idx] = (filter[0] * src[idx - 1] + filter[1] * src[idx] + filter[2] * src[idx + 1] + filter[3] * src[idx + 2]) >> 1;
    }
    src = (uint16_t*)((char*)src + srcstride * sizeof(uint16_t));
    tmp += 64;
}
}
