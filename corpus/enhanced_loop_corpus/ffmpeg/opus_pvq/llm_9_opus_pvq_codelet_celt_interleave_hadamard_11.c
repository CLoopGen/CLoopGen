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
    int limit = stride * N0;
    for (int idx = 0; idx < limit; idx++) {
        int i = idx % stride;
        int j = idx / stride;
        tmp[j * stride + i] = X[order[i] * N0 + j] + X[order[i] * N0 + (j + 1) % N0] - X[order[i] * N0 + (j + 2) % N0];
    }
}
