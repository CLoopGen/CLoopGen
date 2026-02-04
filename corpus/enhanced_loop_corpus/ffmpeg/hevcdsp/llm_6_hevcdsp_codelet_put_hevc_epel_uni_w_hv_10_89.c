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
    int z;
    for (y = 0; y < height + 3; y++) {
        for (x = 0; x < width; x++) {
            z = x >> 1;
            tmp[z] = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 2;
        }
        src += srcstride;
        tmp += 32; // Adjusted stride due to write every other element
    }
}
