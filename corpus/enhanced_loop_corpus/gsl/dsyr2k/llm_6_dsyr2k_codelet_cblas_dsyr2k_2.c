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
    for (i = 0; i < N; i++) {
        double temp = beta;
        for (j = i; j < N; j++) {
            double val = C[ldc * i + j];
            val *= temp;
            C[ldc * i + j] = val;
        }
    }
}
