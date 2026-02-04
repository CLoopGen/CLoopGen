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
for (i = 0; i < N; i++) {
    int idx_diag = 2 * (ldc * i + i);
    (((double *)C)[idx_diag]) *= beta;
    (((double *)C)[idx_diag + 1]) = 0.;
    for (j = i + 1; j < N; j++) {
        int idx_off = 2 * (ldc * i + j);
        double temp_real = (((double *)C)[idx_off]) * beta;
        double temp_imag = (((double *)C)[idx_off + 1]) * beta;
        (((double *)C)[idx_off]) = temp_real;
        (((double *)C)[idx_off + 1]) = temp_imag;
    }
}
}
