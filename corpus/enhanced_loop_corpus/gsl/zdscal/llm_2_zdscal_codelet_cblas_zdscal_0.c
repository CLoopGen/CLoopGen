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
    for (i = 0; i < N; i++) {
        x_ptr[2 * ix] *= alpha;
        x_ptr[2 * ix + 1] *= alpha;
        ix += incX;
    }
}
