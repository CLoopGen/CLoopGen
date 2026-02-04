#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
doublereal *e = NULL;
integer i__1 = 0;
doublereal d__1;
doublereal d__2;
doublereal d__3;
integer i__ = 0;
doublereal anorm = 0.0;

void init_vars() {
    const size_t data_size = 1 << 20; // 1 million elements
    i__1 = (integer)data_size;

    d__ = (doublereal*)calloc(data_size + 1, sizeof(doublereal));
    e = (doublereal*)calloc(data_size + 1, sizeof(doublereal));

    for (size_t i = 1; i <= data_size; ++i) {
        d__[i] = sin((doublereal)i) * 100.0;
        e[i] = cos((doublereal)i) * 100.0;
    }

    anorm = 0.0;
}