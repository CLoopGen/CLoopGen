#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            if (i > 0 && j > 0) {
                C[ldc * i + j] = C[ldc * (i-1) + (j-1)] + 1.0;
            } else {
                C[ldc * i + j] = 0.0;
            }
        }
    }
}
