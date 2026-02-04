#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT (*dst)[2];
extern INTFLOAT (*src0)[2];
extern INTFLOAT *src1;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    int64_t s0 = src0[i][0];
    int64_t s1 = src0[i][1];
    int64_t w = src1[i];
    int64_t temp0 = s0 * w + 32768;
    int64_t temp1 = s1 * w + 32768;
    int64_t shifted0 = temp0 >> 16;
    int64_t shifted1 = temp1 >> 16;
    dst[i][0] = (int)shifted0;
    dst[i][1] = (int)shifted1;
}
}
