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
    tmp[0] = -7 * src1[0] + 42 * src1[1] + 96 * src1[2] - 2 * src1[3] - src1[4];
    tmp[1] = -7 * src1[1] + 42 * src1[2] + 96 * src1[3] - 2 * src1[4] - src1[5];
    tmp[2] = -7 * src1[2] + 42 * src1[3] + 96 * src1[4] - 2 * src1[5] - src1[6];
    tmp[3] = -7 * src1[3] + 42 * src1[4] + 96 * src1[5] - 2 * src1[6] - src1[7];
    tmp += 4;
    src1 += srcStride;
}
}
