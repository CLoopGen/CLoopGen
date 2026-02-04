#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y += 2) {
    for (x = 0; x < width; x++) {
        int32_t sum = 0;
        for (int k = 0; k < 4; k++) {
            sum += filter[k] * src[x + k - 3];
        }
        dst[x] = (sum) >> 2;
    }
    if (y + 1 < height) {
        for (x = 0; x < width; x++) {
            int32_t sum = 0;
            for (int k = 4; k < 8; k++) {
                sum += filter[k] * src[x + k - 3];
            }
            dst[x] = (sum) >> 2;
        }
    }
    src += srcstride;
    dst += 64;
    if (y + 1 < height) {
        src += srcstride;
        dst += 64;
    }
}
}
