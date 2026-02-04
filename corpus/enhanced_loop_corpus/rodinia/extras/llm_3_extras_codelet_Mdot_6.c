#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double *x;
extern double *y;
extern int i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(len * sizeof(int));
    for (i = 0; i < len; i++) {
        indices[i] = i;
    }
    for (i = 0; i < len; i++) {
        int idx = indices[i];
        sum += x[idx] * y[idx];
    }
    free(indices);
}
