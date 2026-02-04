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
    if (h + 5 > 0) {
        int full_iters = (h + 5) / 4;
        int remainder = (h + 5) % 4;

        for (i = 0; i < full_iters; i++) {
            // Unroll 4 iterations of the original loop
            for (int step = 0; step < 4; step++) {
                tmp[0] = 0 * src1[-2] + -1 * src1[-1] + 5 * src1[0] + 5 * src1[1] + -1 * src1[2] + 0 * src1[3];
                tmp[1] = 0 * src1[-1] + -1 * src1[0] + 5 * src1[1] + 5 * src1[2] + -1 * src1[3] + 0 * src1[4];
                tmp[2] = 0 * src1[0] + -1 * src1[1] + 5 * src1[2] + 5 * src1[3] + -1 * src1[4] + 0 * src1[5];
                tmp[3] = 0 * src1[1] + -1 * src1[2] + 5 * src1[3] + 5 * src1[4] + -1 * src1[5] + 0 * src1[6];
                tmp[4] = 0 * src1[2] + -1 * src1[3] + 5 * src1[4] + 5 * src1[5] + -1 * src1[6] + 0 * src1[7];
                tmp[5] = 0 * src1[3] + -1 * src1[4] + 5 * src1[5] + 5 * src1[6] + -1 * src1[7] + 0 * src1[8];
                tmp[6] = 0 * src1[4] + -1 * src1[5] + 5 * src1[6] + 5 * src1[7] + -1 * src1[8] + 0 * src1[9];
                tmp[7] = 0 * src1[5] + -1 * src1[6] + 5 * src1[7] + 5 * src1[8] + -1 * src1[9] + 0 * src1[10];
                tmp += 8;
                src1 += srcStride;
            }
        }

        // Handle remaining iterations (0 to 3)
        for (i = 0; i < remainder; i++) {
            tmp[0] = 0 * src1[-2] + -1 * src1[-1] + 5 * src1[0] + 5 * src1[1] + -1 * src1[2] + 0 * src1[3];
            tmp[1] = 0 * src1[-1] + -1 * src1[0] + 5 * src1[1] + 5 * src1[2] + -1 * src1[3] + 0 * src1[4];
            tmp[2] = 0 * src1[0] + -1 * src1[1] + 5 * src1[2] + 5 * src1[3] + -1 * src1[4] + 0 * src1[5];
            tmp[3] = 0 * src1[1] + -1 * src1[2] + 5 * src1[3] + 5 * src1[4] + -1 * src1[5] + 0 * src1[6];
            tmp[4] = 0 * src1[2] + -1 * src1[3] + 5 * src1[4] + 5 * src1[5] + -1 * src1[6] + 0 * src1[7];
            tmp[5] = 0 * src1[3] + -1 * src1[4] + 5 * src1[5] + 5 * src1[6] + -1 * src1[7] + 0 * src1[8];
            tmp[6] = 0 * src1[4] + -1 * src1[5] + 5 * src1[6] + 5 * src1[7] + -1 * src1[8] + 0 * src1[9];
            tmp[7] = 0 * src1[5] + -1 * src1[6] + 5 * src1[7] + 5 * src1[8] + -1 * src1[9] + 0 * src1[10];
            tmp += 8;
            src1 += srcStride;
        }
    }
}
