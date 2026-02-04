#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dst;
extern  double *src0;
extern  double *src1;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (i = 0; i < len; i += stride) {
        if (i + 1 < len) {
            dst[i] = src0[i] * src1[i];
            dst[i + 1] = src0[i + 1] * src1[i + 1];
        } else {
            dst[i] = src0[i] * src1[i];
        }
    }
}
