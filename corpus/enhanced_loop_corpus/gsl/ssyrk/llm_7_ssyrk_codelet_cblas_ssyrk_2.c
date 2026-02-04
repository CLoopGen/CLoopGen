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
    int offset;
    for (j = 0; j < N; j++) {
        for (i = 0; i <= j; i++) {
            offset = ldc * i + j;
            C[offset] = C[offset] * beta;
        }
    }
}
