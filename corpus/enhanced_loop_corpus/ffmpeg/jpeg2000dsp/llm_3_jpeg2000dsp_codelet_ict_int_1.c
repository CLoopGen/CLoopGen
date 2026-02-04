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
    int offset = i & (csize - 1); // Indirect, wrap-around indexing (assumes csize is power of two)
    int idx = offset; // Simulate indirect access via computed index
    i0 = src0[idx] + src2[idx] + ((int)((26345U * src2[idx]) + (1 << 15)) >> 16);
    i1 = src0[idx] - ((int)(((unsigned int)i_ict_params[1] * src1[idx]) + (1 << 15)) >> 16) - ((int)(((unsigned int)i_ict_params[2] * src2[idx]) + (1 << 15)) >> 16);
    i2 = src0[idx] + (2 * src1[idx]) + ((int)((-14942U * src1[idx]) + (1 << 15)) >> 16);
    src0[idx] = i0;
    src1[idx] = i1;
    src2[idx] = i2;
}
}
