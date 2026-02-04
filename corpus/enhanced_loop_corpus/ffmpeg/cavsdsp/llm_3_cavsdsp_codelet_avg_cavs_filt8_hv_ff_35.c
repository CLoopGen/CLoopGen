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



void loop() {
    for (i = 0; i < w; i++) {
        int offset = i * 8;
        const int16_t *tmp_offset = &tmp[offset];
        uint8_t *dst_local[8];
        int indices[] = {0, 1, 2, 3, 4, 5, 6, 7};

        for (int j = 0; j < 8; j++) {
            dst_local[j] = &dst[j * dstStride];
        }

        const int coeffs[8][6] = {
            {-1, -2, 96, 42, -7, 0},
            {-1, -2, 96, 42, -7, 0},
            {-1, -2, 96, 42, -7, 0},
            {-1, -2, 96, 42, -7, 0},
            {-1, -2, 96, 42, -7, 0},
            {-1, -2, 96, 42, -7, 0},
            {-1, -2, 96, 42, -7, 0},
            {-1, -2, 96, 42, -7, 0}
        };

        for (int j = 0; j < 8; j++) {
            int idx = indices[j];
            int val = coeffs[j][0] * tmp_offset[(idx - 2)*8 / 8] +
                      coeffs[j][1] * tmp_offset[(idx - 1)*8 / 8] +
                      coeffs[j][2] * tmp_offset[idx * 8 / 8] +
                      coeffs[j][3] * tmp_offset[(idx + 1)*8 / 8] +
                      coeffs[j][4] * tmp_offset[(idx + 2)*8 / 8] +
                      coeffs[j][5] * tmp_offset[(idx + 3)*8 / 8] +
                      64 * src2[idx * srcStride];

            dst_local[j][0] = ((dst_local[j][0]) + cm[(val + 512) >> 10] + 1) >> 1;
        }

        tmp++;
        src2++;
    }
}
