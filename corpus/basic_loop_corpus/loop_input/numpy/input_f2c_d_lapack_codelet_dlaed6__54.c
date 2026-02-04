#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
doublereal *z__ = NULL;
integer i__ = 0;
doublereal dscale[3];
doublereal sclfac;
doublereal zscale[3];

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB per array (double: 8 bytes)

    d__ = (doublereal*) malloc(data_size * sizeof(doublereal));
    z__ = (doublereal*) malloc(data_size * sizeof(doublereal));

    if (!d__ || !z__) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        d__[i] = sin(i * 0.01);
        z__[i] = cos(i * 0.01);
    }

    sclfac = 1.5;

    i__ = 1;
}