#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern int *src0;
extern int len;
extern int i;
extern int *src1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i += 2) {
        float r0 = src0[i] * (1.F / (2.F * 2147483647));
        r0 += src1[i] * (1.F / (2.F * 2147483647));
        dst[i] = r0;

        if (i + 1 < len) {
            float r1 = src0[i+1] * (1.F / (2.F * 2147483647));
            r1 += src1[i+1] * (1.F / (2.F * 2147483647));
            dst[i+1] = r1;
        }
    }
}
