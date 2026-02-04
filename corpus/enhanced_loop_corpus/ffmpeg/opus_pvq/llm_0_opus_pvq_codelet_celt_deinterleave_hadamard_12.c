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
    int idx_i = i / N0;
    int idx_j = i % N0;
    tmp[order[idx_i] * N0 + idx_j] = X[idx_j * stride + idx_i];
}
}
