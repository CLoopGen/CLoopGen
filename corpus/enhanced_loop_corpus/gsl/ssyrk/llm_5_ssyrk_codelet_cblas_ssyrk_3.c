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
for (i = 0; i < N; i++) {
    int limit = (i < N/2) ? i + 1 : (N + 1) / 2;
    for (j = 0; j < limit; j++) {
        C[ldc * i + j] *= beta;
    }
}
}
