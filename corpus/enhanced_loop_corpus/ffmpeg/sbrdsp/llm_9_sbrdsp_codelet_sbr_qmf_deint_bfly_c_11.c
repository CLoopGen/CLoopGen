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
    for (i = 0; i < 128; i += 4) {
        v[i]     = src0[i/2] - src1[63 - (i/2)];
        v[i + 1] = src0[i/2] + src1[63 - (i/2)];
        v[i + 2] = src0[i/2 + 1] - src1[63 - (i/2 + 1)];
        v[i + 3] = src0[i/2 + 1] + src1[63 - (i/2 + 1)];
    }
}
