#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp1;
extern double *dp2;
extern double *out;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(len * sizeof(int));
    for (i = 0; i < len; i++) {
        indices[i] = i;
    }
    for (i = 0; i < len; i++) {
        int idx = indices[i];
        out[idx] = dp1[idx] + dp2[idx];
    }
    free(indices);
}
