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
            float temp1 = (((float *)C)[2 * (ldc * i + j)]);
            float temp2 = (((float *)C)[2 * (ldc * i + j) + 1]);
            temp1 *= beta;
            temp2 *= beta;
            (((float *)C)[2 * (ldc * i + j)]) = temp1;
            (((float *)C)[2 * (ldc * i + j) + 1]) = temp2;
        }
        int idx = 2 * (ldc * i + i);
        (((float *)C)[idx]) *= beta;
        (((float *)C)[idx + 1]) = 0;
    }
}
