#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *k;
extern doublereal *q;
extern doublereal *dlamda;
extern doublereal *w;
extern integer q_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Modify memory access pattern to use strided access with pointer arithmetic
    doublereal *w_ptr = w + 1;
    doublereal *dlamda_j_ptr;
    integer j_stride = q_dim1;
    for (j = 1; j <= i__1; ++j) {
        dlamda_j_ptr = dlamda + j;
        // First inner loop: i from 1 to j-1
        i__2 = j - 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            w_ptr[i__ - 1] *= q[i__ + j * j_stride] / (dlamda[i__] - *dlamda_j_ptr);
        }
        // Second inner loop: i from j+1 to k
        i__2 = *k;
        for (i__ = j + 1; i__ <= i__2; ++i__) {
            w_ptr[i__ - 1] *= q[i__ + j * j_stride] / (dlamda[i__] - *dlamda_j_ptr);
        }
    }
}
