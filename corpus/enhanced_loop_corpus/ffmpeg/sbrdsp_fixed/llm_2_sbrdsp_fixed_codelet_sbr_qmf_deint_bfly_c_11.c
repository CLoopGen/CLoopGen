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
    // Variant 1: Strided memory access with stride of 2
    // Access elements in a strided pattern instead of consecutive
    for (i = 0; i < 64; i += 2) {
        int j = i >> 1; // j ranges from 0 to 31
        v[2 * j] = (int)(16U + src0[2 * j] - src1[63 - 2 * j]) >> 5;
        v[127 - 2 * j] = (int)(16U + src0[2 * j] + src1[63 - 2 * j]) >> 5;
        if (i + 1 < 64) {
            v[2 * j + 1] = (int)(16U + src0[2 * j + 1] - src1[63 - (2 * j + 1)]) >> 5;
            v[127 - (2 * j + 1)] = (int)(16U + src0[2 * j + 1] + src1[63 - (2 * j + 1)]) >> 5;
        }
    }
}
