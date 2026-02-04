#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef double doublereal;
typedef int integer;

doublereal *r__;
integer i__1;
integer i__;
doublereal safmx2;

void init_vars() {
    safmx2 = 2.0;
    i__1 = 1000000;
    r__ = (doublereal*)malloc(i__1 * sizeof(doublereal));
    if (r__ == NULL) exit(1);
    *r__ = 1.0;
}