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
for (i = 0; i < csize; i += 2) {
    if (i + 1 >= csize) break;
    // Unroll the loop by factor of 2 to increase computational intensity
    // First iteration
    i0 = *src0 + *src2 + ((int)((26345U * *src2) + (1 << 15)) >> 16);
    i1 = *src0 - ((int)(((unsigned int)i_ict_params[1] * *src1) + (1 << 15)) >> 16) - ((int)(((unsigned int)i_ict_params[2] * *src2) + (1 << 15)) >> 16);
    i2 = *src0 + (2 * *src1) + ((int)((-14942U * *src1) + (1 << 15)) >> 16);
    *src0++ = i0;
    *src1++ = i1;
    *src2++ = i2;

    // Second iteration
    i0 = *src0 + *src2 + ((int)((26345U * *src2) + (1 << 15)) >> 16);
    i1 = *src0 - ((int)(((unsigned int)i_ict_params[1] * *src1) + (1 << 15)) >> 16) - ((int)(((unsigned int)i_ict_params[2] * *src2) + (1 << 15)) >> 16);
    i2 = *src0 + (2 * *src1) + ((int)((-14942U * *src1) + (1 << 15)) >> 16);
    *src0++ = i0;
    *src1++ = i1;
    *src2++ = i2;
}
}
