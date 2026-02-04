#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src[];
extern int srcStride[];
extern uint8_t *dst;
extern int dstStride;
extern int srcSliceH;
extern int alpha_first;
extern int width;
extern int x;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (h = 0; h < srcSliceH; h++) {
        uint8_t *dest = dst + dstStride * h;
        if (alpha_first) {
            for (x = 0; x < width; x++) {
                uint8_t s3 = src[3][x];
                uint8_t s0 = src[0][x];
                uint8_t s1 = src[1][x];
                uint8_t s2 = src[2][x];
                *dest++ = s3;
                *dest++ = s0;
                *dest++ = s1;
                *dest++ = s2;
            }
        } else {
            for (x = 0; x < width; x++) {
                uint8_t s0 = src[0][x];
                uint8_t s1 = src[1][x];
                uint8_t s2 = src[2][x];
                uint8_t s3 = src[3][x];
                *dest++ = s0;
                *dest++ = s1;
                *dest++ = s2;
                *dest++ = s3;
            }
        }
        for (i = 0; i < 4; i++)
            src[i] += srcStride[i];
    }
}
