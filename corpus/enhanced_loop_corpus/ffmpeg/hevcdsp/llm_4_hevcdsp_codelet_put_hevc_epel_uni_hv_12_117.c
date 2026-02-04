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
        if (y % 2 == 0) {
            for (x = 0; x < width; x++) {
                tmp[x] = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 4;
            }
        } else {
            for (x = 0; x < width; x += 2) {
                int val = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 4;
                tmp[x] = val;
                if (x + 1 < width) tmp[x + 1] = val;
            }
        }
        src += srcstride;
        tmp += 64;
    }
}
