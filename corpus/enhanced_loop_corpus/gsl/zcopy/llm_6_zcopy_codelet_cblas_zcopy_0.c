#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  void *X;
extern  int incX;
extern void *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *y_ptr = (double *)Y;
    const double *x_ptr = (const double *)X;
    int local_iy = iy;
    int local_ix = ix;
    for (i = 0; i < N; i++) {
        y_ptr[2 * local_iy] = x_ptr[2 * local_ix];
        y_ptr[2 * local_iy + 1] = x_ptr[2 * local_ix + 1];
        local_ix += incX;
        local_iy += incY;
    }
    iy = local_iy;
    ix = local_ix;
}
