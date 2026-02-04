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
        if (beta == 1.0f) {
            (((float *)C)[2 * (ldc * i + i) + 1]) = 0.;
        } else {
            (((float *)C)[2 * (ldc * i + i)]) *= beta;
            (((float *)C)[2 * (ldc * i + i) + 1]) = 0.;
        }
        for (j = i + 1; j < N; j++) {
            float *ptr = &(((float *)C)[2 * (ldc * i + j)]);
            if (beta != 0.0f) {
                ptr[0] *= beta;
                ptr[1] *= beta;
            } else {
                ptr[0] = 0.0f;
                ptr[1] = 0.0f;
            }
        }
    }
}
