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
    // Variant 1: Strided memory access with stride of 2 (processing even indices only)
    for (i = 0; i < n; i += 2) {
        if (i < n) {
            dst[i][0] = src0[i][0] * src1[i];
            dst[i][1] = src0[i][1] * src1[i];
        }
    }
}
