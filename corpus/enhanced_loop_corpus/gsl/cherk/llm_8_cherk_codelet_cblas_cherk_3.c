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
    for (j = 0; j <= i; j++) {
        float *base = &(((float *)C)[2 * (ldc * i + j)]);
        if (j == i) {
            base[0] *= beta;
            base[1] = 0;
        } else {
            base[0] *= beta;
            base[1] *= beta;
        }
    }
}
}
