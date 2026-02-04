#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double beta;
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 2;
for (i = 0; i < n1; i += stride) {
    if (i + 1 < n1) {
        for (j = 0; j < n2; j++) {
            C[ldc * i + j] *= beta;
            C[ldc * (i + 1) + j] *= beta;
        }
    } else {
        for (j = 0; j < n2; j++) {
            C[ldc * i + j] *= beta;
        }
    }
}
}
