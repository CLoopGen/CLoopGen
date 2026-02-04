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
for (i = 0; i < N; ++i) {
    int start = i;
    for (j = start; j < N; ++j) {
        if (C[ldc * i + j] == 0.0f) 
            continue;
        C[ldc * i + j] *= beta;
    }
}
}
