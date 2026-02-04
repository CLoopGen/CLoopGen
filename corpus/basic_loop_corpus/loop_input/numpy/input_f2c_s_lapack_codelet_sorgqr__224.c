#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef float real;
typedef int integer;

real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer kk;

void init_vars() {
    // Set matrix dimensions and loop bounds
    a_dim1 = 4096;  // leading dimension
    kk = 512;
    i__1 = 1024;  // j goes from kk+1 to i__1
    i__2 = kk;    // i goes from 1 to kk

    // Allocate enough memory to cover indices up to i__1 * a_dim1 + kk
    // Max index accessed: a[i__ + j * a_dim1] where i__ <= kk, j <= i__1
    // So max index is approximately kk + i__1 * a_dim1
    ptrdiff_t total_size = (i__1 + 1) * a_dim1 + kk;
    a = (real*)calloc(total_size, sizeof(real));
    if (!a) {
        exit(1);
    }
}