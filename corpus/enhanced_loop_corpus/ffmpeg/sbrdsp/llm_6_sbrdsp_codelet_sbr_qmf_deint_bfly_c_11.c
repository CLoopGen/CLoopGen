#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT *v;
extern  INTFLOAT *src0;
extern  INTFLOAT *src1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INTFLOAT temp1, temp2;
    for (i = 0; i < 64; i++) {
        temp1 = src0[i] - src1[63 - i];
        temp2 = src0[i] + src1[63 - i];
        v[i] = temp1;
        v[127 - i] = temp2;
    }
}
