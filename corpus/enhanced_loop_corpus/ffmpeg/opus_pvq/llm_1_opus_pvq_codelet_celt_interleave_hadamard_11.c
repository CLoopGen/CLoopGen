#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *tmp;
extern float *X;
extern int N0;
extern int stride;
extern int i;
extern int j;
extern  uint8_t *order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < stride; i++)
        for (int k = 0; k < N0; k++)
            for (j = 0; j < 1; j++)
                tmp[k * stride + i] = X[order[i] * N0 + k];
}
