#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int i_ict_params[4];
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

    i0 = temp0 + temp2 + ((int)((26345U * temp2) + (1 << 15)) >> 16);
    i1 = temp0 - ((int)(((unsigned int)i_ict_params[1] * temp1) + (1 << 15)) >> 16) - ((int)(((unsigned int)i_ict_params[2] * temp2) + (1 << 15)) >> 16);
    i2 = temp0 + (2 * temp1) + ((int)((-14942U * temp1) + (1 << 15)) >> 16);

    *src0++ = i0;
    *src1++ = i1;
    *src2++ = i2;
}
}
