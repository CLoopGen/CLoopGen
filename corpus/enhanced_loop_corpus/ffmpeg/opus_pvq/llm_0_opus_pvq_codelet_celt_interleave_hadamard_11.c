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
    for (i = 0; i < stride * N0; i++) {
        int idx = i;
        int j = idx % N0;
        int i_val = idx / N0;
        if (i_val < stride)
            tmp[j * stride + i_val] = X[order[i_val] * N0 + j];
    }
}
