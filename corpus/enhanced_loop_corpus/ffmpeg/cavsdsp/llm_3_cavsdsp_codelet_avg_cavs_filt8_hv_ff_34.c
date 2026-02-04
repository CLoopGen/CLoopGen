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
    uint8_t *s = &src1[idx];
    tmp[0] = -1 * s[-1] + 5 * s[0] + 5 * s[1] - 1 * s[2] + 0 * s[3];
    tmp[1] = -1 * s[0] + 5 * s[1] + 5 * s[2] - 1 * s[3] + 0 * s[4];
    tmp[2] = -1 * s[1] + 5 * s[2] + 5 * s[3] - 1 * s[4] + 0 * s[5];
    tmp[3] = -1 * s[2] + 5 * s[3] + 5 * s[4] - 1 * s[5] + 0 * s[6];
    tmp[4] = -1 * s[3] + 5 * s[4] + 5 * s[5] - 1 * s[6] + 0 * s[7];
    tmp[5] = -1 * s[4] + 5 * s[5] + 5 * s[6] - 1 * s[7] + 0 * s[8];
    tmp[6] = -1 * s[5] + 5 * s[6] + 5 * s[7] - 1 * s[8] + 0 * s[9];
    tmp[7] = -1 * s[6] + 5 * s[7] + 5 * s[8] - 1 * s[9] + 0 * s[10];
    tmp += 8;
}
}
