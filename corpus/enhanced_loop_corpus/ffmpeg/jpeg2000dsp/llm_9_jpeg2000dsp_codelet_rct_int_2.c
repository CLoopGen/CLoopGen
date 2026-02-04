#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int csize;
extern int32_t *src0;
extern int32_t *src1;
extern int32_t *src2;
extern int32_t i0;
extern int32_t i1;
extern int32_t i2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < csize; i++) {
    int32_t temp0 = *src0;
    int32_t temp1 = *src1;
    int32_t temp2 = *src2;
    i1 = temp0 - ((temp2 + temp1) >> 2);
    i0 = i1 + temp2 + temp1;
    i2 = i1 - temp1 + (temp0 & 0x3);
    *src0++ = i0 ^ temp1;
    *src1++ = i1 + (temp0 >> 1);
    *src2++ = i2 + temp2;
}
}
