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
        for (x = 0; x < width; x += 2) {
            int32_t sum1 = (filter[0] * src[x - 3] + filter[1] * src[x - 2] + 
                            filter[2] * src[x - 1] + filter[3] * src[x] + 
                            filter[4] * src[x + 1] + filter[5] * src[x + 2] + 
                            filter[6] * src[x + 3] + filter[7] * src[x + 4]);
            int32_t sum2 = (filter[0] * src[x - 2] + filter[1] * src[x - 1] + 
                            filter[2] * src[x]     + filter[3] * src[x + 1] + 
                            filter[4] * src[x + 2] + filter[5] * src[x + 3] + 
                            filter[6] * src[x + 4] + filter[7] * src[x + 5]);
            tmp[x]     = sum1 >> 1;
            if (x + 1 < width)
                tmp[x + 1] = sum2 >> 1;
        }
        src += srcstride;
        tmp += 64;
    }
}
