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
    const uint8_t *s = src1;
    int16_t *t = tmp;
    // Use consecutive memory access with manual pointer arithmetic unrolling
    t[0] = 5*(int)s[0] + 5*(int)s[1] - (int)s[-1] - (int)s[2];
    t[1] = 5*(int)s[1] + 5*(int)s[2] - (int)s[0]  - (int)s[3];
    t[2] = 5*(int)s[2] + 5*(int)s[3] - (int)s[1]  - (int)s[4];
    t[3] = 5*(int)s[3] + 5*(int)s[4] - (int)s[2]  - (int)s[5];
    t[4] = 5*(int)s[4] + 5*(int)s[5] - (int)s[3]  - (int)s[6];
    t[5] = 5*(int)s[5] + 5*(int)s[6] - (int)s[4]  - (int)s[7];
    t[6] = 5*(int)s[6] + 5*(int)s[7] - (int)s[5]  - (int)s[8];
    t[7] = 5*(int)s[7] + 5*(int)s[8] - (int)s[6]  - (int)s[9];
    tmp += 8;
    src1 += srcStride;
}
}
