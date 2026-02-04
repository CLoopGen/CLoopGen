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
    double *C_ptr = (double *)C;
    for (i = 0; i < N; i++) {
        int base_idx = 2 * ldc * i;
        for (j = 0; j < i; j++) {
            int idx = base_idx + 2 * j;
            double temp1 = C_ptr[idx] * beta;
            double temp2 = C_ptr[idx + 1] * beta;
            C_ptr[idx] = temp1;
            C_ptr[idx + 1] = temp2;
        }
        int diag_idx = base_idx + 2 * i;
        C_ptr[diag_idx] *= beta;
        C_ptr[diag_idx + 1] = 0;
    }
}
