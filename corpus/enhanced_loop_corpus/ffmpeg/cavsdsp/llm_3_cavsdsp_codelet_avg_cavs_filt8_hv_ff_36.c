#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    ptrdiff_t j;
    int sum[8] = {0};
    for (j = 0; j < 8; j++) {
        const int idx_base = j * 8;
        const int tmp_idx = tmp[idx_base];
        const int tmp_offsets[11] = {
            tmp[-2 * 8], tmp[-1 * 8], tmp[0 * 8], tmp[1 * 8], tmp[2 * 8],
            tmp[3 * 8], tmp[4 * 8], tmp[5 * 8], tmp[6 * 8], tmp[7 * 8], tmp[8 * 8]
        };
        const int coeffs[6][8] = {
            {-1, -2, 96, 42, -7, 0},  
            {-1, -2, 96, 42, -7, 0},
            {-1, -2, 96, 42, -7, 0},
            {-1, -2, 96, 42, -7, 0},
            {-1, -2, 96, 42, -7, 0},
            {-1, -2, 96, 42, -7, 0}
        };
        const int cidx = j;
        int val = 0;
        switch(j) {
            case 0: val = (-1*tmp_offsets[0] + -2*tmp_offsets[1] + 96*tmp_offsets[2] + 42*tmp_offsets[3] + -7*tmp_offsets[4] + 0*tmp_offsets[5]); break;
            case 1: val = (-1*tmp_offsets[1] + -2*tmp_offsets[2] + 96*tmp_offsets[3] + 42*tmp_offsets[4] + -7*tmp_offsets[5] + 0*tmp_offsets[6]); break;
            case 2: val = (-1*tmp_offsets[2] + -2*tmp_offsets[3] + 96*tmp_offsets[4] + 42*tmp_offsets[5] + -7*tmp_offsets[6] + 0*tmp_offsets[7]); break;
            case 3: val = (-1*tmp_offsets[3] + -2*tmp_offsets[4] + 96*tmp_offsets[5] + 42*tmp_offsets[6] + -7*tmp_offsets[7] + 0*tmp_offsets[8]); break;
            case 4: val = (-1*tmp_offsets[4] + -2*tmp_offsets[5] + 96*tmp_offsets[6] + 42*tmp_offsets[7] + -7*tmp_offsets[8] + 0*tmp_offsets[9]); break;
            case 5: val = (-1*tmp_offsets[5] + -2*tmp_offsets[6] + 96*tmp_offsets[7] + 42*tmp_offsets[8] + -7*tmp_offsets[9] + 0*tmp_offsets[10]); break;
            case 6: val = (-1*tmp_offsets[6] + -2*tmp_offsets[7] + 96*tmp_offsets[8] + 42*tmp_offsets[9] + -7*tmp_offsets[10] + 0); break;
            case 7: val = (-1*tmp_offsets[7] + -2*tmp_offsets[8] + 96*tmp_offsets[9] + 42*tmp_offsets[10] + -7*tmp_offsets[11] + 0); break;
        }
        sum[j] = (dst[cidx * dstStride] + cm[(val + 512) >> 10] + 1) >> 1;
    }
    for (j = 0; j < 8; j++) {
        dst[j * dstStride] = sum[j];
    }
    dst++;
    tmp++;
}
}
