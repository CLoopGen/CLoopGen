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
for (y = 0; y < height + 7; y += 2) {
    for (x = 0; x < width; x++) {
        int offset1 = x - 3, offset2 = x - 2, offset3 = x - 1;
        int offset4 = x, offset5 = x + 1, offset6 = x + 2, offset7 = x + 3, offset8 = x + 4;
        tmp[x] = (filter[0] * src[offset1] + filter[1] * src[offset2] + filter[2] * src[offset3] +
                  filter[3] * src[offset4] + filter[4] * src[offset5] + filter[5] * src[offset6] +
                  filter[6] * src[offset7] + filter[7] * src[offset8]) >> 1;
    }
    src += srcstride;
    tmp += 64;

    if (y + 1 < height + 7) {
        for (x = 0; x < width; x++) {
            int offset1 = x - 3, offset2 = x - 2, offset3 = x - 1;
            int offset4 = x, offset5 = x + 1, offset6 = x + 2, offset7 = x + 3, offset8 = x + 4;
            tmp[x] = (filter[0] * src[offset1] + filter[1] * src[offset2] + filter[2] * src[offset3] +
                      filter[3] * src[offset4] + filter[4] * src[offset5] + filter[5] * src[offset6] +
                      filter[6] * src[offset7] + filter[7] * src[offset8]) >> 1;
        }
        src += srcstride;
        tmp += 64;
    }
}
}
