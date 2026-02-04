#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double beta;
extern double *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) { // Increase loop stride to reduce trip count
    for (j = 0; j <= i; j += 2) {
        double temp = C[ldc * i + j] * beta;
        C[ldc * i + j] = temp;
        if (i + 1 < N && j + 1 <= i + 1) {
            C[ldc * (i+1) + (j+1)] *= beta; // Operate on off-diagonal elements with reduced frequency
        }
    }
}
}
