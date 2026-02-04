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
for (i = 0; i < N; i += 2) {
    int upper_i = i + 1 < N ? i + 1 : i;
    for (j = 0; j < i; j++) {
        (((float *)C)[2 * (ldc * i + j)]) *= beta;
        (((float *)C)[2 * (ldc * i + j) + 1]) *= beta;
        if (i != upper_i) {
            (((float *)C)[2 * (ldc * upper_i + j)]) *= beta;
            (((float *)C)[2 * (ldc * upper_i + j) + 1]) *= beta;
        }
    }
    (((float *)C)[2 * (ldc * i + i)]) *= beta;
    (((float *)C)[2 * (ldc * i + i) + 1]) = 0;
    if (i != upper_i) {
        (((float *)C)[2 * (ldc * upper_i + upper_i)]) *= beta;
        (((float *)C)[2 * (ldc * upper_i + upper_i) + 1]) = 0;
    }
}
}
