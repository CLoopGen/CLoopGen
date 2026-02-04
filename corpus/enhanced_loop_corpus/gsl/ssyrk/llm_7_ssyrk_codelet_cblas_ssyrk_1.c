#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *local_C = (float*)calloc(ldc * N, sizeof(float));
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            local_C[ldc * i + j] = 0.;
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            C[ldc * i + j] = local_C[ldc * i + j];
        }
    }
    free(local_C);
}
