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
            for (x = 0; x < width * 4; x += 4) {
                dest[x + 0] = src[3][x / 4];
                dest[x + 1] = src[0][x / 4];
                dest[x + 2] = src[1][x / 4];
                dest[x + 3] = src[2][x / 4];
            }
        } else {
            for (x = 0; x < width * 4; x += 4) {
                dest[x + 0] = src[0][x / 4];
                dest[x + 1] = src[1][x / 4];
                dest[x + 2] = src[2][x / 4];
                dest[x + 3] = src[3][x / 4];
            }
        }
        for (i = 0; i < 4; i++)
            src[i] += srcStride[i];
    }
}
