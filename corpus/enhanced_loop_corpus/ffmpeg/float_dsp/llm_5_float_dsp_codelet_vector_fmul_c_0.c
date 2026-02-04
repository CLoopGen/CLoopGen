#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  float *src0;
extern  float *src1;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        if (src0[i] == 0.0f || src1[i] == 0.0f) {
            dst[i] = 0.0f;
            continue;
        }
        dst[i] = src0[i] * src1[i];
    }
}
