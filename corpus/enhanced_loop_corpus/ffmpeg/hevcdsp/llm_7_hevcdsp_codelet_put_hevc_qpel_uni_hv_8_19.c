#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height + 7; y++) {
        for (x = 0; x < width; x += 2) {
            int16_t val0, val1;
            int offset = x;
            val0 = (filter[0] * src[offset - 3] + filter[1] * src[offset - 2] +
                    filter[2] * src[offset - 1] + filter[3] * src[offset] +
                    filter[4] * src[offset + 1] + filter[5] * src[offset + 2] +
                    filter[6] * src[offset + 3] + filter[7] * src[offset + 4]) >> 8;
            if (x + 1 < width) {
                val1 = (filter[0] * src[offset + 1 - 3] + filter[1] * src[offset + 1 - 2] +
                        filter[2] * src[offset + 1 - 1] + filter[3] * src[offset + 1] +
                        filter[4] * src[offset + 1 + 1] + filter[5] * src[offset + 1 + 2] +
                        filter[6] * src[offset + 1 + 3] + filter[7] * src[offset + 1 + 4]) >> 8;
                tmp[x + 1] = val1;
            }
            tmp[x] = val0;
        }
        src += srcstride;
        tmp += 64;
    }
}
