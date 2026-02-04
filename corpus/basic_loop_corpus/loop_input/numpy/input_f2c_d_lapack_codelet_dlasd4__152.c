#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *z__ = NULL;
doublereal *delta = NULL;
doublereal *work = NULL;
integer i__1 = 0;
integer j = 0;
doublereal psi = 0.0;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data per array (doubles)
    i__1 = (integer)(data_size / sizeof(doublereal));

    z__ = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    delta = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    work = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));

    if (!z__ || !delta || !work) {
        exit(1);
    }

    for (integer idx = 1; idx <= i__1; ++idx) {
        z__[idx] = (doublereal)(idx % 123 + 1);
        delta[idx] = (doublereal)(idx % 456 + 1);
        work[idx] = (doublereal)(idx % 789 + 1);
    }

    psi = 0.0;
}