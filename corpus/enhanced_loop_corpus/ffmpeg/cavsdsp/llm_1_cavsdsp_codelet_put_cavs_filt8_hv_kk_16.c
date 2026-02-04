#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern ptrdiff_t srcStride;
extern int16_t *tmp;
extern  int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h + 5; i++) {
        for (int unroll_factor = 0; unroll_factor < 8; unroll_factor += 4) {
            tmp[unroll_factor + 0] = 0 * src1[unroll_factor - 2] + (-7) * src1[unroll_factor - 1] +
                                     42 * src1[unroll_factor + 0] + 96 * src1[unroll_factor + 1] +
                                     (-2) * src1[unroll_factor + 2] + (-1) * src1[unroll_factor + 3];
            tmp[unroll_factor + 1] = 0 * src1[unroll_factor - 1] + (-7) * src1[unroll_factor + 0] +
                                     42 * src1[unroll_factor + 1] + 96 * src1[unroll_factor + 2] +
                                     (-2) * src1[unroll_factor + 3] + (-1) * src1[unroll_factor + 4];
            tmp[unroll_factor + 2] = 0 * src1[unroll_factor + 0] + (-7) * src1[unroll_factor + 1] +
                                     42 * src1[unroll_factor + 2] + 96 * src1[unroll_factor + 3] +
                                     (-2) * src1[unroll_factor + 4] + (-1) * src1[unroll_factor + 5];
            tmp[unroll_factor + 3] = 0 * src1[unroll_factor + 1] + (-7) * src1[unroll_factor + 2] +
                                     42 * src1[unroll_factor + 3] + 96 * src1[unroll_factor + 4] +
                                     (-2) * src1[unroll_factor + 5] + (-1) * src1[unroll_factor + 6];
        }
        tmp += 8;
        src1 += srcStride;
    }
}
