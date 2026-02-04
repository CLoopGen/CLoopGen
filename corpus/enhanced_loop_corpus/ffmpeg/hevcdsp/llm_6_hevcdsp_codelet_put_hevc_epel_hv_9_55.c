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
    int8_t f0 = filter[0], f1 = filter[1], f2 = filter[2], f3 = filter[3];
    for (y = 0; y < height + 3; y++) {
        int16_t prev_tmp = 0;
        for (x = 0; x < width; x++) {
            tmp[x] = (f0 * src[x - 1] + f1 * src[x] + f2 * src[x + 1] + f3 * src[x + 2]) >> 1;
            prev_tmp = tmp[x]; 
        }
        src += srcstride;
        tmp += 64;
    }
}
