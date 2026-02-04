#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;
integer k3;
integer k4;
doublereal mul;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // Aim for ~64 MB to ensure measurable runtime
    
    a_dim1 = (integer)sqrt((double)target_bytes / sizeof(doublereal));
    i__1 = a_dim1 / 2;
    k3 = a_dim1;
    k4 = a_dim1 + 100;
    mul = 1.5;

    // Allocate 2D array as column-major (Fortran-style) with leading dimension a_dim1
    a = (doublereal*)calloc(a_dim1 * a_dim1, sizeof(doublereal));
    
    // Initialize with non-zero values to make scaling observable
    for (integer idx = 0; idx < a_dim1 * a_dim1; ++idx) {
        a[idx] = (doublereal)(idx % 127 + 1);
    }
}