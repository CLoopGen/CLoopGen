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
for (i = 0; i < n; i++) {
    INTFLOAT s0 = src0[i][0];
    INTFLOAT s1 = src0[i][1];
    INTFLOAT w = src1[i];
    dst[i][0] = s0 * w;
    dst[i][1] = s1 * w;
    dst[i][0] += (s1 * w) * 0.1f;
    dst[i][1] -= (s0 * w) * 0.1f;
}
}
