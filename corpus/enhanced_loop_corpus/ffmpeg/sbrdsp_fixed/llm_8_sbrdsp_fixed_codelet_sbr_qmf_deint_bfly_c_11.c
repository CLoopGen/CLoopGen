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
for (i = 0; i < 128; i++) {
    int idx = i >> 1;
    int rev_idx = 63 - idx;
    INTFLOAT s0 = src0[idx];
    INTFLOAT s1 = src1[rev_idx];
    if (i & 1) {
        v[127 - idx] = (int)(16U + s0 + s1) >> 5;
    } else {
        v[idx] = (int)(16U + s0 - s1) >> 5;
    }
}
}
