#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double beta;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *C_base = (double *)C;
    ptrdiff_t stride = 2 * ldc;
    for (i = 0; i < N; i++) {
        double *C_row = C_base + 2 * i; 
        C_row[i * 2] *= beta;
        C_row[i * 2 + 1] = 0;
        for (j = i + 1; j < N; j++) {
            C_row[j * 2] *= beta;
            C_row[j * 2 + 1] *= beta;
        }
    }
}
