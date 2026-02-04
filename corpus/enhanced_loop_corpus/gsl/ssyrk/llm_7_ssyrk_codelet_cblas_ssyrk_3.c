#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern float *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < N; i++) {
        for (j = 0; j <= i; j++) {
            C[ldc * i + j] *= beta;
            if (j > 0) {
                C[ldc * i + j] += C[ldc * i + (j - 1)]; 
            }
        }
    }
}
