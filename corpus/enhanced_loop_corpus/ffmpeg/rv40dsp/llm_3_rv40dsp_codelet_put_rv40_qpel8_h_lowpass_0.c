#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int h;
extern  int C1;
extern  int C2;
extern  int SHIFT;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int offsets_src[8][11] = {
    {-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8},
    {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
    {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
    {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
    {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}
};
for (i = 0; i < h; i++) {
    int k;
    for (k = 0; k < 8; k++) {
        int base_idx = offsets_src[k][0];
        dst[k] = cm[(src[base_idx + 0] + src[base_idx + 5] - 5 * (src[base_idx + 1] + src[base_idx + 4]) +
                     src[base_idx + 2] * C1 + src[base_idx + 3] * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    }
    dst += dstStride;
    src += srcStride;
}
}
