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
    int outer = len / 1000 + 1;
    int chunk = 1000;
    for (i = 0; i < outer; i++) {
        int start = i * chunk;
        int end = (start + chunk < len) ? start + chunk : len;
        for (int k = start; k < end; k++)
            dst[k] = src0[k] * src1[k];
    }
}
