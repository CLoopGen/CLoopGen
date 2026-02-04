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
    int offset = (i & 1) ? 0 : 1;  // Alternate computation pattern based on even/odd index

    if (i % 3 != 0) {
        tmp[0] = 0 * src1[offset - 2] + -7 * src1[offset - 1] + 42 * src1[offset + 0] + 96 * src1[offset + 1] + -2 * src1[offset + 2] + -1 * src1[offset + 3];
        tmp[1] = 0 * src1[offset - 1] + -7 * src1[offset + 0] + 42 * src1[offset + 1] + 96 * src1[offset + 2] + -2 * src1[offset + 3] + -1 * src1[offset + 4];
        tmp[2] = 0 * src1[offset + 0] + -7 * src1[offset + 1] + 42 * src1[offset + 2] + 96 * src1[offset + 3] + -2 * src1[offset + 4] + -1 * src1[offset + 5];
        tmp[3] = 0 * src1[offset + 1] + -7 * src1[offset + 2] + 42 * src1[offset + 3] + 96 * src1[offset + 4] + -2 * src1[offset + 5] + -1 * src1[offset + 6];
        tmp[4] = 0 * src1[offset + 2] + -7 * src1[offset + 3] + 42 * src1[offset + 4] + 96 * src1[offset + 5] + -2 * src1[offset + 6] + -1 * src1[offset + 7];
        tmp[5] = 0 * src1[offset + 3] + -7 * src1[offset + 4] + 42 * src1[offset + 5] + 96 * src1[offset + 6] + -2 * src1[offset + 7] + -1 * src1[offset + 8];
        tmp[6] = 0 * src1[offset + 4] + -7 * src1[offset + 5] + 42 * src1[offset + 6] + 96 * src1[offset + 7] + -2 * src1[offset + 8] + -1 * src1[offset + 9];
        tmp[7] = 0 * src1[offset + 5] + -7 * src1[offset + 6] + 42 * src1[offset + 7] + 96 * src1[offset + 8] + -2 * src1[offset + 9] + -1 * src1[offset + 10];
    } else {
        for (int j = 0; j < 8; j++) {
            tmp[j] = (src1[j + 5] << 1) - 32;  // Alternative computation every third iteration
        }
    }
    tmp += 8;
    src1 += srcStride;
}
}
