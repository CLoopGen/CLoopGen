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
    int8_t *base = (int8_t*)src1;
    tmp[0] = -1 * base[-1] + 5 * base[0] + 5 * base[1] + -1 * base[2];
    tmp[1] = -1 * base[0] + 5 * base[1] + 5 * base[2] + -1 * base[3];
    tmp[2] = -1 * base[1] + 5 * base[2] + 5 * base[3] + -1 * base[4];
    tmp[3] = -1 * base[2] + 5 * base[3] + 5 * base[4] + -1 * base[5];
    tmp[4] = -1 * base[3] + 5 * base[4] + 5 * base[5] + -1 * base[6];
    tmp[5] = -1 * base[4] + 5 * base[5] + 5 * base[6] + -1 * base[7];
    tmp[6] = -1 * base[5] + 5 * base[6] + 5 * base[7] + -1 * base[8];
    tmp[7] = -1 * base[6] + 5 * base[7] + 5 * base[8] + -1 * base[9];
    tmp += 8;
    src1 += srcStride;
}
}
