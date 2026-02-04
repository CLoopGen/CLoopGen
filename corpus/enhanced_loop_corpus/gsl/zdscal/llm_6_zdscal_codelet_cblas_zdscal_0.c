#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern void *X;
extern  int incX;
extern int i;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *x_ptr = (double *)X;
    int temp_ix = ix;
    for (i = 0; i < N; i++) {
        double val0 = x_ptr[2 * temp_ix];
        double val1 = x_ptr[2 * temp_ix + 1];
        val0 *= alpha;
        val1 *= alpha;
        x_ptr[2 * temp_ix] = val0;
        x_ptr[2 * temp_ix + 1] = val1;
        temp_ix += incX;
    }
}
