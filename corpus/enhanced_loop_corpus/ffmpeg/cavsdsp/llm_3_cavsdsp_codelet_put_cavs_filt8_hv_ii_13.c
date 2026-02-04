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
    const ptrdiff_t idx = srcStride * i;
    tmp[0] = -1 * src1[idx - 2] + -2 * src1[idx - 1] + 96 * src1[idx + 0] + 42 * src1[idx + 1] + -7 * src1[idx + 2];
    tmp[1] = -1 * src1[idx - 1] + -2 * src1[idx + 0] + 96 * src1[idx + 1] + 42 * src1[idx + 2] + -7 * src1[idx + 3];
    tmp[2] = -1 * src1[idx + 0] + -2 * src1[idx + 1] + 96 * src1[idx + 2] + 42 * src1[idx + 3] + -7 * src1[idx + 4];
    tmp[3] = -1 * src1[idx + 1] + -2 * src1[idx + 2] + 96 * src1[idx + 3] + 42 * src1[idx + 4] + -7 * src1[idx + 5];
    tmp[4] = -1 * src1[idx + 2] + -2 * src1[idx + 3] + 96 * src1[idx + 4] + 42 * src1[idx + 5] + -7 * src1[idx + 6];
    tmp[5] = -1 * src1[idx + 3] + -2 * src1[idx + 4] + 96 * src1[idx + 5] + 42 * src1[idx + 6] + -7 * src1[idx + 7];
    tmp[6] = -1 * src1[idx + 4] + -2 * src1[idx + 5] + 96 * src1[idx + 6] + 42 * src1[idx + 7] + -7 * src1[idx + 8];
    tmp[7] = -1 * src1[idx + 5] + -2 * src1[idx + 6] + 96 * src1[idx + 7] + 42 * src1[idx + 8] + -7 * src1[idx + 9];
    tmp += 8;
}
}
