#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *v;
extern  INTFLOAT *src0;
extern  INTFLOAT *src1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; i++) {
    int j = 63 - i;
    INTFLOAT a0 = src0[i], a1 = src0[j];
    INTFLOAT b0 = src1[i], b1 = src1[j];
    
    v[i]           = (int)(16U + a0 - b1) >> 5;
    v[j]           = (int)(16U + a1 - b0) >> 5;
    v[127 - i]     = (int)(16U + a0 + b1) >> 5;
    v[127 - j]     = (int)(16U + a1 + b0) >> 5;
}
}
