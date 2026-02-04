#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  float *src;
extern float mul;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(len * sizeof(int));
    if (!indices) return;
    for (i = 0; i < len; i++) {
        indices[i] = len - 1 - i; // reverse access pattern
    }
    for (i = 0; i < len; i++) {
        int j = indices[i];
        dst[j] = src[j] * mul;
    }
    free(indices);
}
