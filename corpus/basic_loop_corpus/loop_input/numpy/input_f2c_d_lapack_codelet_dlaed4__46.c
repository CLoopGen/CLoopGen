#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *z__;
doublereal *delta;
integer i__1;
integer j;
doublereal psi;
doublereal dpsi;
doublereal temp;
doublereal erretm;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of total data (two arrays)
    i__1 = (integer)(data_size / sizeof(doublereal));

    z__ = (doublereal*)aligned_alloc(32, (i__1 + 1) * sizeof(doublereal));
    delta = (doublereal*)aligned_alloc(32, (i__1 + 1) * sizeof(doublereal));

    for (integer i = 1; i <= i__1; ++i) {
        z__[i] = sin((doublereal)i);
        delta[i] = cos((doublereal)i) + 1.5;
    }

    psi = 0.0;
    dpsi = 0.0;
    erretm = 0.0;
    j = 0;
}