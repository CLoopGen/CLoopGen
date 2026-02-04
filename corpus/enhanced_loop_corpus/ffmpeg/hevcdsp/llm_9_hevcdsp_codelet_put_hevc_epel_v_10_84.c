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
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x += 4) {
            for (int k = 0; k < 4 && (x + k) < width; k++) {
                int idx = x + k;
                int32_t sum = filter[0] * src[idx - srcstride];
                sum += filter[1] * src[idx];
                sum += filter[2] * src[idx + srcstride];
                sum += filter[3] * src[idx + 2*srcstride];
                dst[idx] = sum >> 2;
            }
        }
        src += srcstride;
        dst += 64;
    }
}
