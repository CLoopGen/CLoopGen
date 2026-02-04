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
for (i = 0; i < N; i += 2) {
    if (i < N) {
        for (j = i; j < N; j++) {
            C[ldc * i + j] = 0.;
            if (i + 1 < N && j >= i + 1) {
                C[ldc * (i + 1) + j] = 0.;
            }
        }
    }
}
}
