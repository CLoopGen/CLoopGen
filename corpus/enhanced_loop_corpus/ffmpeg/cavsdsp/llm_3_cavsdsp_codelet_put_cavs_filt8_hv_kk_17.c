#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src2;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    ptrdiff_t idx = i;
    const int tmp_vals[13] = {
        tmp[-2 * 8], tmp[-1 * 8], tmp[0 * 8], tmp[1 * 8], tmp[2 * 8],
        tmp[3 * 8], tmp[4 * 8], tmp[5 * 8], tmp[6 * 8], tmp[7 * 8],
        tmp[8 * 8], tmp[9 * 8], tmp[10 * 8]
    };

    for (int j = 0; j < 8; j++) {
        int val = (
            0 * tmp_vals[j + 0] +
            -1 * tmp_vals[j + 1] +
            5 * tmp_vals[j + 2] +
            5 * tmp_vals[j + 3] +
            -1 * tmp_vals[j + 4] +
            0 * tmp_vals[j + 5] +
            64 * src2[j * srcStride]
        );
        dst[j * dstStride] = cm[(val + 512) >> 10];
    }

    dst++;
    tmp++;
    src2++;
}
}
