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
    int offset = (i % 2 == 0) ? 0 : 1;

    if (offset == 0) {
        tmp[0] = -7 * src1[-1 + offset] + 42 * src1[0 + offset] + 96 * src1[1 + offset] + -2 * src1[2 + offset] + -1 * src1[3 + offset];
        tmp[1] = -7 * src1[0 + offset] + 42 * src1[1 + offset] + 96 * src1[2 + offset] + -2 * src1[3 + offset] + -1 * src1[4 + offset];
        tmp[2] = -7 * src1[1 + offset] + 42 * src1[2 + offset] + 96 * src1[3 + offset] + -2 * src1[4 + offset] + -1 * src1[5 + offset];
        tmp[3] = -7 * src1[2 + offset] + 42 * src1[3 + offset] + 96 * src1[4 + offset] + -2 * src1[5 + offset] + -1 * src1[6 + offset];
    } else {
        tmp[4] = -7 * src1[3 + offset] + 42 * src1[4 + offset] + 96 * src1[5 + offset] + -2 * src1[6 + offset] + -1 * src1[7 + offset];
        tmp[5] = -7 * src1[4 + offset] + 42 * src1[5 + offset] + 96 * src1[6 + offset] + -2 * src1[7 + offset] + -1 * src1[8 + offset];
        tmp[6] = -7 * src1[5 + offset] + 42 * src1[6 + offset] + 96 * src1[7 + offset] + -2 * src1[8 + offset] + -1 * src1[9 + offset];
        tmp[7] = -7 * src1[6 + offset] + 42 * src1[7 + offset] + 96 * src1[8 + offset] + -2 * src1[9 + offset] + -1 * src1[10 + offset];
    }

    if (i % 2 == 0) {
        for (int j = 4; j < 8; j++) tmp[j] = 0;
    } else {
        for (int j = 0; j < 4; j++) tmp[j] = 0;
    }

    tmp += 8;
    src1 += srcStride;
}
}
