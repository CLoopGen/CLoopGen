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
    double temp = 0.0;
    for (i = 0; i < len; i++) {
        temp = src0[i] * src1[i];
        dst[i] = temp;
    }
}
