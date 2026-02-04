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
    for (i = 0; i < len; i++) {
        if (i % 2 == 0) {
            dst[i] = src0[i] * src1[i];
        } else {
            dst[i] = 0.0;
        }
    }
}
