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
    for (j = 0; j < i; j++) {
        float *ptr = &(((float *)C)[2 * (ldc * i + j)]);
        if (i % 2 == 0) {
            ptr[0] *= beta;
        } else {
            ptr[0] = ptr[0] * beta + 1.0f;
        }
        ptr[1] *= beta;
    }
    float *diag_ptr = &(((float *)C)[2 * (ldc * i + i)]);
    diag_ptr[0] *= beta;
    diag_ptr[1] = (i == 0) ? 0 : diag_ptr[1] * beta;
}
}
