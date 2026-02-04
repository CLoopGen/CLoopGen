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
    for (int j = 0; j < len; j++)
        indices[j] = rand() % len;
    for (i = 0; i < len; i++)
        dst[indices[i]] += src[indices[i]] * mul;
    free(indices);
}
