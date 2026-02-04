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
    int stride = 4;
    for (i = 0; i < len; i += stride) {
        for (int j = 0; j < stride; j++) {
            if (i + j < len)
                dst[i + j] = src0[i + j] * src1[i + j];
        }
    }
}
