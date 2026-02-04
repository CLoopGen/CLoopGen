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
for (i = 0; i < h + 3; i++) {
    tmp[0] = -1 * src1[-2] + -2 * src1[-1] + 96 * src1[0] + 42 * src1[1] + -7 * src1[2];
    tmp[1] = -1 * src1[-1] + -2 * src1[0] + 96 * src1[1] + 42 * src1[2] + -7 * src1[3];
    tmp[2] = -1 * src1[0] + -2 * src1[1] + 96 * src1[2] + 42 * src1[3] + -7 * src1[4];
    tmp[3] = -1 * src1[1] + -2 * src1[2] + 96 * src1[3] + 42 * src1[4] + -7 * src1[5];
    tmp += 4;
    src1 += srcStride;
}
}
