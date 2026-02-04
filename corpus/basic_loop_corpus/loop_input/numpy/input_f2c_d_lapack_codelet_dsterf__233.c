#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
doublereal *e = NULL;
integer i__1;
doublereal c__;
integer i__;
integer m;
doublereal p;
doublereal r__;
doublereal s;
doublereal bb;
doublereal gamma;
doublereal alpha;
doublereal sigma;
doublereal oldgam;
doublereal oldc;

void init_vars() {
    const size_t array_size = 20000000; // ~160 MB for two arrays of doubles

    d__ = (doublereal*)calloc(array_size, sizeof(doublereal));
    e = (doublereal*)calloc(array_size, sizeof(doublereal));

    if (!d__ || !e) {
        exit(1);
    }

    for (size_t i = 0; i < array_size; ++i) {
        d__[i] = (doublereal)(i + 1) * 0.5;
        e[i] = (doublereal)(i + 1) * 0.3;
    }

    m = 1;
    i__1 = (integer)array_size - 2;
    p = 1.0;
    c__ = 1.0;
    s = 0.5;
    gamma = 0.1;
    sigma = 0.01;
    oldgam = 0.05;
    oldc = 0.9;
}