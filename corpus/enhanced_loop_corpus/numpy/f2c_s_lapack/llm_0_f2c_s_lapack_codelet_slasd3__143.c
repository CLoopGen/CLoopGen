#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *q;
extern integer q_dim1;
extern integer i__1;
extern integer i__;
extern integer ktemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computation to access adjacent elements
    // Here, we assume ktemp is positive and adjust the loop to traverse in increasing order of memory layout
    // Assuming column-major order (Fortran-style), we maintain i__ as row index, but ensure access strides are minimized
    integer base_idx = ktemp * q_dim1;
    for (i__ = 1; i__ <= i__1; ++i__) {
        q[i__ + base_idx] = q[i__ + q_dim1];
    }
}
