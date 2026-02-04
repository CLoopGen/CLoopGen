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
    // Variant 2: Use indirect and strided read with prefetching-like access pattern via pointer arithmetic
    // Increase stride in reading X while maintaining scatter write to tmp
    float *tmp_base = tmp;
    for (i = 0; i < stride; i++) {
        float *X_ptr = X + order[i] * N0;
        for (j = 0; j < N0; j++) {
            tmp_base[j * stride + i] = X_ptr[j];
        }
    }
}
