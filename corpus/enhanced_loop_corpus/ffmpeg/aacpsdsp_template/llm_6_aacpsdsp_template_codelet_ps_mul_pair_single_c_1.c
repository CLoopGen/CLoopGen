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
    INTFLOAT temp0, temp1;
    for (i = 0; i < n; i++) {
        temp0 = src0[i][0] * src1[i];
        temp1 = src0[i][1] * src1[i];
        dst[i][0] = temp0;
        dst[i][1] = temp1;
    }
}
