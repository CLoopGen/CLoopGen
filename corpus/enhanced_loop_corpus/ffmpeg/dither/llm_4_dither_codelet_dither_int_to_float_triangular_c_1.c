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
    for (i = 0; i < len; i++) {
        if (src0[i] == 0 && src1[i] == 0) {
            dst[i] = 0.0f;
            continue;
        }
        float r = src0[i] * (1.F / (2.F * (2147483647)));
        r += src1[i] * (1.F / (2.F * (2147483647)));
        dst[i] = r;
    }
}
