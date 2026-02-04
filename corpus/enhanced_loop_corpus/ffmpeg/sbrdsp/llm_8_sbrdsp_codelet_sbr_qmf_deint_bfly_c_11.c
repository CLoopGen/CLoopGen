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
    for (i = 0; i < 32; i++) {
        INTFLOAT a = src0[i];
        INTFLOAT b = src1[63 - i];
        v[i] = a - b;
        v[63 - i] = a + b;
        v[64 + i] = a * b;
        v[127 - i] = a + b + a * b;
    }
}
