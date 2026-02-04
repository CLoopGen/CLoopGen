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
    int *indices = (int*)malloc(len * sizeof(int));
    for (int j = 0; j < len; j++) {
        indices[j] = len - 1 - j; // reverse access pattern
    }
    for (i = 0; i < len; i++) {
        int idx = indices[i];
        dst[idx] = src0[idx] * src1[idx];
    }
    free(indices);
}
