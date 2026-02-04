#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    const int src_offsets[] = {
        -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };
    const int coeffs[8][6] = {
        {0, -1, 5, 5, -1, 0},
        {0, -1, 5, 5, -1, 0},
        {0, -1, 5, 5, -1, 0},
        {0, -1, 5, 5, -1, 0},
        {0, -1, 5, 5, -1, 0},
        {0, -1, 5, 5, -1, 0},
        {0, -1, 5, 5, -1, 0},
        {0, -1, 5, 5, -1, 0}
    };

    for (int j = 0; j < 8; j++) {
        int sum = 0;
        for (int k = 0; k < 6; k++) {
            int idx = src_offsets[j + k] * srcStride;
            sum += coeffs[j][k] * src[idx];
        }
        dst[j * dstStride] = cm[(sum + 4) >> 3];
    }

    dst++;
    src++;
}
}
