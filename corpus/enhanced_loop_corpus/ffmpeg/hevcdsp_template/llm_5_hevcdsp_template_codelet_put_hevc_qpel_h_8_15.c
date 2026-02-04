#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
        int sum = 0;
        if (x >= 3 && x + 4 < width) {
            sum = (filter[0] * src[x - 3] + filter[1] * src[x - 2] + filter[2] * src[x - 1] + filter[3] * src[x] + 
                   filter[4] * src[x + 1] + filter[5] * src[x + 2] + filter[6] * src[x + 3] + filter[7] * src[x + 4]);
        } else {
            for (int k = 0; k < 8; k++) {
                int idx = x + k - 3;
                if (idx < 0) idx = 0;
                if (idx >= width) idx = width - 1;
                sum += filter[k] * src[idx];
            }
        }
        dst[x] = sum >> 8;
    }
    src += srcstride;
    dst += 64;
}
}
