#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *z__ = NULL;
doublereal *delta = NULL;
integer i__1;
integer j;
doublereal psi;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of total data (2 arrays)

    z__ = (doublereal *)aligned_alloc(32, data_size * sizeof(doublereal));
    delta = (doublereal *)aligned_alloc(32, data_size * sizeof(doublereal));

    if (!z__ || !delta) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        z__[i] = (doublereal)(i + 1);
        delta[i] = (doublereal)(i + 1) + 0.1;
    }

    i__1 = (integer)data_size - 1;
    psi = 0.0;
}