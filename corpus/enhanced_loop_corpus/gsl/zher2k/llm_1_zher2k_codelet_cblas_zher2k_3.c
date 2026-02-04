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
        if (j < i) {
            (((double *)C)[2 * (ldc * i + j)]) *= beta;
            (((double *)C)[2 * (ldc * i + j) + 1]) *= beta;
        } else {
            (((double *)C)[2 * (ldc * i + i)]) *= beta;
            (((double *)C)[2 * (ldc * i + i) + 1]) = 0.;
        }
    }
}
}
