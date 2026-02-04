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
    (((float *)C)[2 * (ldc * i + i)]) *= beta;
    (((float *)C)[2 * (ldc * i + i) + 1]) = 0;
    j = i + 1;
    for (; j < N; j++) {
        (((float *)C)[2 * (ldc * i + j)]) *= beta;
        (((float *)C)[2 * (ldc * i + j) + 1]) *= beta;
    }
}
}
