#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *a;
doublereal *work;
integer a_dim1;
integer i__1;
integer i__2;
doublereal d__1;
integer i__;
integer j;
doublereal sum;
doublereal absa;

void init_vars() {
    const int size = 4096;  // Adjusted for ~0.01s runtime (empirically tuned)

    a_dim1 = size;
    i__1 = size;

    a = (doublereal*)calloc(size * size, sizeof(doublereal));
    work = (doublereal*)calloc(size, sizeof(doublereal));

    for (int idx = 0; idx < size * size; ++idx) {
        a[idx] = (double)(idx % 127) - 64.0;
    }
}