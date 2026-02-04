#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    for (int j = 0; j < 8; j++) {
        int coeffs[8][4] = {
            {0,1,0,2, 0,3,1,3},
            {1,2,0,3, 0,4,1,5},
            {2,3,1,4, 0,5,0,6},
            {3,4,2,5, 1,6,0,7},
            {4,5,3,6, 2,7,1,8},
            {5,6,4,7, 3,8,2,8},
            {6,7,5,8, 4,8,3,7},
            {7,8,6,8, 5,7,4,6}
        };
        int a = coeffs[j][0], b = coeffs[j][1];
        int c = coeffs[j][2], d = coeffs[j][3];
        int e = coeffs[j][4], f = coeffs[j][5];
        int g = coeffs[j][6], l = coeffs[j][7];
        dst[j] = cm[(((src[a] + src[b]) * 20 - (src[c] + src[d]) * 6 + (src[e] + src[f]) * 3 - (src[g] + src[l])) + 16) >> 5];
    }
    dst += dstStride;
    src += srcStride;
}
}
