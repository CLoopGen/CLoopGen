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
    // Variant 1: Strided Memory Access (stride of 2)
    for (i = 0; i < 64; i += 2) {
        int idx = i * 2;
        if (idx < 64) {
            v[idx] = src0[idx] - src1[63 - idx];
            v[127 - idx] = src0[idx] + src1[63 - idx];
        }
        idx++;
        if (idx < 64) {
            v[idx] = src0[idx] - src1[63 - idx];
            v[127 - idx] = src0[idx] + src1[63 - idx];
        }
    }
}
