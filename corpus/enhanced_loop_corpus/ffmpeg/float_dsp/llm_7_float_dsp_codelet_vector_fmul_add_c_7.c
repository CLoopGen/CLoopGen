#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  float *src0;
extern  float *src1;
extern  float *src2;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < len; i++) {
        dst[i] = src0[i-1] * src1[i] + src2[i];
    }
    if (len > 0) {
        dst[0] = src0[0] * src1[0] + src2[0];
    }
}
