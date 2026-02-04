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
    tmp[0] = -1 * src1[-2] + -2 * src1[-1] + 96 * src1[0] + 42 * src1[1] + -7 * src1[2];
    tmp[1] = -1 * src1[-1] + -2 * tmp[0]/8 + 96 * src1[1] + 42 * src1[2] + -7 * src1[3];  
    tmp[2] = -1 * tmp[0]/8 + -2 * tmp[1]/8 + 96 * src1[2] + 42 * src1[3] + -7 * src1[4];
    tmp[3] = -1 * tmp[1]/8 + -2 * tmp[2]/8 + 96 * src1[3] + 42 * src1[4] + -7 * src1[5];
    tmp[4] = -1 * tmp[2]/8 + -2 * tmp[3]/8 + 96 * src1[4] + 42 * src1[5] + -7 * src1[6];
    tmp[5] = -1 * tmp[3]/8 + -2 * tmp[4]/8 + 96 * src1[5] + 42 * src1[6] + -7 * src1[7];
    tmp[6] = -1 * tmp[4]/8 + -2 * tmp[5]/8 + 96 * src1[6] + 42 * src1[7] + -7 * src1[8];
    tmp[7] = -1 * tmp[5]/8 + -2 * tmp[6]/8 + 96 * src1[7] + 42 * src1[8] + -7 * src1[9];

    tmp += 8;
    src1 += srcStride;
}
}
