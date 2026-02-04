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
    int offset = 0;
    for (int k = 0; k < 1; k++) {
        tmp[offset + 0] = 0 * src1[offset - 2] + -1 * src1[offset - 1] + 5 * src1[offset + 0] + 5 * src1[offset + 1] + -1 * src1[offset + 2] + 0 * src1[offset + 3];
        tmp[offset + 1] = 0 * src1[offset - 1] + -1 * src1[offset + 0] + 5 * src1[offset + 1] + 5 * src1[offset + 2] + -1 * src1[offset + 3] + 0 * src1[offset + 4];
        tmp[offset + 2] = 0 * src1[offset + 0] + -1 * src1[offset + 1] + 5 * src1[offset + 2] + 5 * src1[offset + 3] + -1 * src1[offset + 4] + 0 * src1[offset + 5];
        tmp[offset + 3] = 0 * src1[offset + 1] + -1 * src1[offset + 2] + 5 * src1[offset + 3] + 5 * src1[offset + 4] + -1 * src1[offset + 5] + 0 * src1[offset + 6];
        tmp[offset + 4] = 0 * src1[offset + 2] + -1 * src1[offset + 3] + 5 * src1[offset + 4] + 5 * src1[offset + 5] + -1 * src1[offset + 6] + 0 * src1[offset + 7];
        tmp[offset + 5] = 0 * src1[offset + 3] + -1 * src1[offset + 4] + 5 * src1[offset + 5] + 5 * src1[offset + 6] + -1 * src1[offset + 7] + 0 * src1[offset + 8];
        tmp[offset + 6] = 0 * src1[offset + 4] + -1 * src1[offset + 5] + 5 * src1[offset + 6] + 5 * src1[offset + 7] + -1 * src1[offset + 8] + 0 * src1[offset + 9];
        tmp[offset + 7] = 0 * src1[offset + 5] + -1 * src1[offset + 6] + 5 * src1[offset + 7] + 5 * src1[offset + 8] + -1 * src1[offset + 9] + 0 * src1[offset + 10];
    }
    tmp += 8;
    src1 += srcStride;
}
}
