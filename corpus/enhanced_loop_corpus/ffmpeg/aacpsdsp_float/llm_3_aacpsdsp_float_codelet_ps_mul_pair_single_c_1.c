#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT (*dst)[2];
extern INTFLOAT (*src0)[2];
extern INTFLOAT *src1;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive packed access using linear indexing, simulating flattened array layout
    INTFLOAT *dst_flat = &dst[0][0];
    INTFLOAT *src0_flat = &src0[0][0];
    for (i = 0; i < n; i++) {
        int idx = i * 2;
        dst_flat[idx + 0] = src0_flat[idx + 0] * src1[i];
        dst_flat[idx + 1] = src0_flat[idx + 1] * src1[i];
    }
}
