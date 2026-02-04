#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *delta;
doublereal *work;
integer i__1;
integer j;
doublereal eta;

void init_vars() {
    i__1 = 10000000; 

    eta = 0.001;

    delta = (doublereal *)aligned_alloc(32, (i__1 + 1) * sizeof(doublereal));
    work = (doublereal *)aligned_alloc(32, (i__1 + 1) * sizeof(doublereal));

    for (integer i = 1; i <= i__1; ++i) {
        delta[i] = 1.0;
        work[i] = 0.5;
    }
}