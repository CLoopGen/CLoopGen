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
    int outer_i;
    for (outer_i = 0; outer_i < N; outer_i++) {
        int temp_ix = ix + outer_i * incX;
        int temp_iy = iy + outer_i * incY;
        for (int unroll_factor = 0; unroll_factor < 1; unroll_factor++) {
            (((double *)Y)[2 * temp_iy]) = (((const double *)X)[2 * temp_ix]);
            (((double *)Y)[2 * temp_iy + 1]) = (((const double *)X)[2 * temp_ix + 1]);
        }
    }
}
