#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *z__ = NULL;
doublereal *delta = NULL;
integer i__1 = 0;
integer j = 0;
doublereal psi = 0.0;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of total data (2 arrays)
    i__1 = data_size;

    z__ = (doublereal*)calloc(data_size + 1, sizeof(doublereal));
    delta = (doublereal*)calloc(data_size + 1, sizeof(doublereal));

    if (!z__ || !delta) {
        exit(1);
    }

    for (size_t idx = 1; idx <= data_size; ++idx) {
        z__[idx] = (doublereal)(idx % 1234);
        delta[idx] = (doublereal)(idx % 5678) + 1.0;
    }

    psi = 0.0;
}