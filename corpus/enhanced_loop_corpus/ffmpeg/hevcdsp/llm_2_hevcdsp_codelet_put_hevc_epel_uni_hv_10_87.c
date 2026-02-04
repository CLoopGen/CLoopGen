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
        int offset = x * 2; // Strided access with step 2
        tmp[x] = (filter[0] * src[offset - 2] + filter[1] * src[offset] + 
                  filter[2] * src[offset + 2] + filter[3] * src[offset + 4]) >> 2;
    }
    src += srcstride;
    tmp += 64;
}
}
