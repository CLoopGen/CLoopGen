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
        int16_t accum = 0;
        for (x = 0; x < width; x++) {
            int32_t center = filter[1] * src[x];
            int32_t left   = filter[0] * src[x - 1];
            int32_t right1 = filter[2] * src[x + 1];
            int32_t right2 = filter[3] * src[x + 2];
            int32_t sum = left + center + right1 + right2;
            dst[x] = (int16_t)(sum >> 8);
            if (x > 0) {
                accum += dst[x - 1]; 
            }
        }
        dst[width] = accum >> 4; 
        src += srcstride;
        dst += 65; 
    }
}
