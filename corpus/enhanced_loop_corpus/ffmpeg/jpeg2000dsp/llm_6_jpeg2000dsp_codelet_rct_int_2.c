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
    int32_t temp_src0, temp_src1, temp_src2;
    for (i = 0; i < csize; i++) {
        temp_src0 = *src0;
        temp_src1 = *src1;
        temp_src2 = *src2;
        i1 = temp_src0 - (temp_src2 + temp_src1 >> 2);
        i0 = i1 + temp_src2;
        i2 = i1 + temp_src1;
        *src0++ = i0;
        *src1++ = i1;
        *src2++ = i2;
    }
}
