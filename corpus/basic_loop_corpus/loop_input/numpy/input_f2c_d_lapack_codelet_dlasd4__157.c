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
doublereal *work;
integer i__1;
integer j;
doublereal psi;
doublereal dpsi;
doublereal temp;
doublereal erretm;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of total data (adjustable)
    i__1 = data_size / sizeof(doublereal);

    z__ = (doublereal*)aligned_alloc(32, (i__1 + 1) * sizeof(doublereal));
    delta = (doublereal*)aligned_alloc(32, (i__1 + 1) * sizeof(doublereal));
    work = (doublereal*)aligned_alloc(32, (i__1 + 1) * sizeof(doublereal));

    for (integer i = 1; i <= i__1; ++i) {
        z__[i] = sin(i);
        delta[i] = cos(i) + 1.5;
        work[i] = 1.0 / (i + 100);
    }

    psi = 0.0;
    dpsi = 0.0;
    temp = 0.0;
    erretm = 0.0;
}