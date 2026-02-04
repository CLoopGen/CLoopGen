#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *a;
real *work;
integer a_dim1;
integer i__1;
integer i__2;
real r__1;
integer i__;
integer j;
real sum;
real absa;

void init_vars() {
    i__1 = 4096; 
    a_dim1 = i__1;

    a = (real*)calloc(a_dim1 * i__1, sizeof(real));
    work = (real*)calloc(i__1, sizeof(real));

    for (int idx = 0; idx < a_dim1 * i__1; ++idx) {
        a[idx] = (real)(rand() % 100) / 10.0f;
    }
}