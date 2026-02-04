#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
integer i__1;
doublereal d__1;
integer i__;
doublereal orgnrm;

void init_vars() {
    i__1 = 20000000; 

    d__ = (doublereal *)malloc(i__1 * sizeof(doublereal));
    if (d__ == NULL) {
        exit(1);
    }

    for (int idx = 0; idx < i__1; ++idx) {
        d__[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }

    orgnrm = 0.0;
    i__ = 1;
    d__1 = 0.0;
}