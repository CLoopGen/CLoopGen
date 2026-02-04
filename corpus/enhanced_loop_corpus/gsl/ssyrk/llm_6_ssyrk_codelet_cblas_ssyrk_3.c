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
        float temp = beta;
        for (j = 0; j <= i; j++) {
            float val = C[ldc * i + j];
            val *= temp;
            C[ldc * i + j] = val;
        }
    }
}
