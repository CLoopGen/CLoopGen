#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double beta;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) {
        int index = 2 * (ldc * i + j);
        double *C_ptr = (double *)C;
        if (j == i) {
            C_ptr[index] *= beta;
            C_ptr[index + 1] = 0;
        } else {
            C_ptr[index] *= beta;
            C_ptr[index + 1] *= beta;
        }
    }
}
}
