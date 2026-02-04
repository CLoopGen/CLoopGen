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
    int offset = (ptrdiff_t)i * srcStride;
    tmp[0] = -7 * src1[offset - 1] + 42 * src1[offset] + 96 * src1[offset + 1] + -2 * src1[offset + 2] + -1 * src1[offset + 3];
    tmp[1] = -7 * src1[offset] + 42 * src1[offset + 1] + 96 * src1[offset + 2] + -2 * src1[offset + 3] + -1 * src1[offset + 4];
    tmp[2] = -7 * src1[offset + 1] + 42 * src1[offset + 2] + 96 * src1[offset + 3] + -2 * src1[offset + 4] + -1 * src1[offset + 5];
    tmp[3] = -7 * src1[offset + 2] + 42 * src1[offset + 3] + 96 * src1[offset + 4] + -2 * src1[offset + 5] + -1 * src1[offset + 6];
    tmp[4] = -7 * src1[offset + 3] + 42 * src1[offset + 4] + 96 * src1[offset + 5] + -2 * src1[offset + 6] + -1 * src1[offset + 7];
    tmp[5] = -7 * src1[offset + 4] + 42 * src1[offset + 5] + 96 * src1[offset + 6] + -2 * src1[offset + 7] + -1 * src1[offset + 8];
    tmp[6] = -7 * src1[offset + 5] + 42 * src1[offset + 6] + 96 * src1[offset + 7] + -2 * src1[offset + 8] + -1 * src1[offset + 9];
    tmp[7] = -7 * src1[offset + 6] + 42 * src1[offset + 7] + 96 * src1[offset + 8] + -2 * src1[offset + 9] + -1 * src1[offset + 10];
    tmp += 8;
    // src1 is now accessed with explicit stride-based indexing instead of pointer update
}
}
