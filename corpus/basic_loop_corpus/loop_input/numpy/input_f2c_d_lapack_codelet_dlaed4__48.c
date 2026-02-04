#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *delta;
integer i__1;
integer j;
doublereal eta;

void init_vars() {
    i__1 = 10000000; // 10 million elements for ~0.01 sec runtime
    eta = 0.001;

    delta = (doublereal*)calloc(i__1 + 1, sizeof(doublereal));
    if (!delta) {
        exit(1);
    }
}