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
                uint8_t pixel[4] = {src[3][x], src[0][x], src[1][x], src[2][x]};
                for (int k = 0; k < 4; k++) {
                    *dest++ = pixel[k];
                }
            }
        } else {
            for (x = 0; x < width; x++) {
                uint8_t pixel[4] = {src[0][x], src[1][x], src[2][x], src[3][x]};
                for (int k = 0; k < 4; k++) {
                    *dest++ = pixel[k];
                }
            }
        }
        for (i = 0; i < 4; i++)
            src[i] += srcStride[i];
    }
}
