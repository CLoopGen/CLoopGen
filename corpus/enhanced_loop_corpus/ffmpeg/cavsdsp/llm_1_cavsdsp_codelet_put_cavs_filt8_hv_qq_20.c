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
        for (int k = 0; k < 8; k++) {
            const int idx = k * 8;
            const int tmp_offsets[] = {
                tmp[-2*8], tmp[-1*8], tmp[0*8], tmp[1*8], tmp[2*8],
                tmp[3*8], tmp[4*8], tmp[5*8], tmp[6*8], tmp[7*8], tmp[8*8], tmp[9*8], tmp[10*8]
            };
            const int coeffs0[] = { 0, -7, 42, 96, -2, -1, 64 };
            const int base_idx = (k == 0) ? 0 : (k == 1) ? 1 : k + 0;

            int sum = 0;
            sum += coeffs0[0] * tmp_offsets[base_idx + 0]; // tmpB or tmpA or tmp[k-2]
            sum += coeffs0[1] * tmp_offsets[base_idx + 1]; // tmpA or tmp0 or ...
            sum += coeffs0[2] * tmp_offsets[base_idx + 2];
            sum += coeffs0[3] * tmp_offsets[base_idx + 3];
            sum += coeffs0[4] * tmp_offsets[base_idx + 4];
            sum += coeffs0[5] * tmp_offsets[base_idx + 5];
            sum += coeffs0[6] * src2[k * srcStride];

            dst[k * dstStride] = cm[(sum + 512) >> 10];
        }
        dst++;
        tmp++;
        src2++;
    }
}
