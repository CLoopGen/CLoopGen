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
for (i = 0; i < N; i++) {
    C[ldc * i + i] = 0.;
    for (j = i + 1; j < N; j++) {
        C[ldc * i + j] = 0.;
    }
}
}
