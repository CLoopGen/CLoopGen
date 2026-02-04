#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *z__ = NULL;
doublereal *delta = NULL;
doublereal *work = NULL;
integer i__1 = 0;
integer j = 0;
doublereal psi = 0.0;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB per array (double), total ~24MB
    i__1 = (integer)data_size;

    z__ = (doublereal*)calloc(data_size + 1, sizeof(doublereal));
    delta = (doublereal*)calloc(data_size + 1, sizeof(doublereal));
    work = (doublereal*)calloc(data_size + 1, sizeof(doublereal));

    for (size_t i = 1; i <= data_size; ++i) {
        z__[i] = (doublereal)(i % 123 + 1);
        delta[i] = (doublereal)(i % 251 + 1);
        work[i] = (doublereal)(i % 199 + 1);
    }

    psi = 0.0;
}