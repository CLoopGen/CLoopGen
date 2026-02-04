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
    for (i = 0; i < 64; i++) {
        if (src0[i] >= src1[63 - i]) {
            v[i] = src0[i] - src1[63 - i];
        } else {
            v[i] = 0.0f;
        }
        v[127 - i] = src0[i] + src1[63 - i];
    }
}
