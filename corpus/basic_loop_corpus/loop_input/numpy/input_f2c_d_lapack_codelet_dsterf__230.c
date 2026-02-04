#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *d__;
doublereal *e;
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
    size_t data_size = 65536;
    m = (integer)(data_size - 1);
    i__1 = 0;
    i__ = m - 1;
    p = 1.0;
    c__ = 1.0;
    gamma = 1.0;
    sigma = 0.1;

    d__ = (doublereal*)aligned_alloc(32, data_size * sizeof(doublereal));
    e = (doublereal*)aligned_alloc(32, data_size * sizeof(doublereal));

    if (!d__ || !e) {
        exit(1);
    }

    for (integer i = 0; i < data_size; ++i) {
        d__[i] = (doublereal)(i + 1) * 0.1;
        e[i] = (doublereal)(i + 1) * 0.2;
    }
}