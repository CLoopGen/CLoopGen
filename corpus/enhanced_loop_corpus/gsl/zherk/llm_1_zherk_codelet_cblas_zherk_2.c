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
    (((double *)C)[2 * (ldc * i + i)]) *= beta;
    (((double *)C)[2 * (ldc * i + i) + 1]) = 0;
    for (j = i + 1; j < N; j++) {
        for (int k = 0; k < 1; k++) {
            (((double *)C)[2 * (ldc * i + j) + k * 2]) *= beta;
            (((double *)C)[2 * (ldc * i + j) + k * 2 + 1]) *= beta;
        }
    }
}
}
