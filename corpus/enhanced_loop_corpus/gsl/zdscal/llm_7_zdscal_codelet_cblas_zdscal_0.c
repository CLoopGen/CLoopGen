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
        x_ptr[2 * temp_ix] *= alpha;
        temp_ix += incX;
        if (i > 0) {
            x_ptr[2 * (temp_ix - incX) + 1] *= alpha;
        }
    }
    if (N > 0) {
        x_ptr[2 * ix + 1] *= alpha;
    }
}
