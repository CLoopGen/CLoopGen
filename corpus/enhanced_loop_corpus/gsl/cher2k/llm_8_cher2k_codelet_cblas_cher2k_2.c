#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    float *c_ptr = (float *)C + 2 * (ldc * i + i);
    c_ptr[0] *= beta;
    c_ptr[1] = 0.0f;
    for (j = i + 1; j < N; j++) {
        c_ptr = (float *)C + 2 * (ldc * i + j);
        c_ptr[0] *= beta;
        c_ptr[1] *= beta;
    }
}
}
