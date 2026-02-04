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
    double *c_ptr = (double *)C;
    ptrdiff_t offset;
    for (i = 0; i < N; i++) {
        offset = 2 * (ldc * i + i);
        c_ptr[offset] *= beta;
        c_ptr[offset + 1] = 0;
        for (j = i + 1; j < N; j++) {
            offset = 2 * (ldc * i + j);
            double temp_real = c_ptr[offset] * beta;
            double temp_imag = c_ptr[offset + 1] * beta;
            c_ptr[offset] = temp_real;
            c_ptr[offset + 1] = temp_imag;
        }
    }
}
