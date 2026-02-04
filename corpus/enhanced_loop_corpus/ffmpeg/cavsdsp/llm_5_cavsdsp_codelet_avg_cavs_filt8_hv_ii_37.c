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
    int offset = (i < (h + 5) / 2) ? 0 : 4;

    if (i >= 2) {
        tmp[offset + 0] = -1 * src1[-2 + offset] + -2 * src1[-1 + offset] + 96 * src1[0 + offset] + 42 * src1[1 + offset] + -7 * src1[2 + offset] + 0 * src1[3 + offset];
        tmp[offset + 1] = -1 * src1[-1 + offset] + -2 * src1[0 + offset] + 96 * src1[1 + offset] + 42 * src1[2 + offset] + -7 * src1[3 + offset] + 0 * src1[4 + offset];
        tmp[offset + 2] = -1 * src1[0 + offset] + -2 * src1[1 + offset] + 96 * src1[2 + offset] + 42 * src1[3 + offset] + -7 * src1[4 + offset] + 0 * src1[5 + offset];
        tmp[offset + 3] = -1 * src1[1 + offset] + -2 * src1[2 + offset] + 96 * src1[3 + offset] + 42 * src1[4 + offset] + -7 * src1[5 + offset] + 0 * src1[6 + offset];
    }

    tmp += 8;
    src1 += srcStride;
}
}
