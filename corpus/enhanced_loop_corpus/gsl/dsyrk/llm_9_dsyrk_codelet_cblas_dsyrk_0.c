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
for (i = 0; i < N; i += 2) {
    for (j = i; j < N; j++) {
        double *row_i = &C[ldc * i + j];
        *row_i = 0.0;
        if (i + 1 < N) {
            double *row_ip1 = &C[ldc * (i + 1) + j];
            *row_ip1 = 0.0;
        }
    }
}
}
