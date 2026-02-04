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
            for (x = 0; x < width; x += 2) {
                int offset = x;
                *dest++ = src[3][offset];     // A1
                *dest++ = src[0][offset];     // R1
                *dest++ = src[1][offset];     // G1
                *dest++ = src[2][offset];     // B1
                if (x + 1 < width) {
                    *dest++ = src[3][offset+1]; // A2
                    *dest++ = src[0][offset+1]; // R2
                    *dest++ = src[1][offset+1]; // G2
                    *dest++ = src[2][offset+1]; // B2
                }
            }
        } else {
            for (x = 0; x < width; x += 2) {
                int offset = x;
                *dest++ = src[0][offset];     // R1
                *dest++ = src[1][offset];     // G1
                *dest++ = src[2][offset];     // B1
                *dest++ = src[3][offset];     // A1
                if (x + 1 < width) {
                    *dest++ = src[0][offset+1]; // R2
                    *dest++ = src[1][offset+1]; // G2
                    *dest++ = src[2][offset+1]; // B2
                    *dest++ = src[3][offset+1]; // A2
                }
            }
        }
        for (i = 0; i < 4; i++)
            src[i] += srcStride[i];
    }
}
