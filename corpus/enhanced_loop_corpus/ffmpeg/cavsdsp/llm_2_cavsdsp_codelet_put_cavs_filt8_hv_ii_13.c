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
    uint8_t *s = src1;
    tmp[0] = -1 * s[-2] + -2 * s[-1] + 96 * s[0] + 42 * s[1] + -7 * s[2];
    tmp[1] = -1 * s[-1] + -2 * s[0] + 96 * s[1] + 42 * s[2] + -7 * s[3];
    tmp[2] = -1 * s[0] + -2 * s[1] + 96 * s[2] + 42 * s[3] + -7 * s[4];
    tmp[3] = -1 * s[1] + -2 * s[2] + 96 * s[3] + 42 * s[4] + -7 * s[5];
    tmp[4] = -1 * s[2] + -2 * s[3] + 96 * s[4] + 42 * s[5] + -7 * s[6];
    tmp[5] = -1 * s[3] + -2 * s[4] + 96 * s[5] + 42 * s[6] + -7 * s[7];
    tmp[6] = -1 * s[4] + -2 * s[5] + 96 * s[6] + 42 * s[7] + -7 * s[8];
    tmp[7] = -1 * s[5] + -2 * s[6] + 96 * s[7] + 42 * s[8] + -7 * s[9];
    tmp += 8;
    src1 += srcStride;
}
}
