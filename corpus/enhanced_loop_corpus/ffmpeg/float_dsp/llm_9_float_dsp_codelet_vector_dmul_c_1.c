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
        double a = src0[i];
        double b = src1[i];
        dst[i] = a * b + a - b + (a * a) - (b * b);
    }
}
