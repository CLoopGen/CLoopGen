#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
doublereal *delta = NULL;
integer i__1 = 0;
integer j = 0;
integer ip1 = 0;
doublereal tau = 0.0;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of total data (adjustable)

    d__ = (doublereal *)aligned_alloc(32, data_size * sizeof(doublereal));
    delta = (doublereal *)aligned_alloc(32, data_size * sizeof(doublereal));

    if (!d__ || !delta) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        d__[i] = (doublereal)(i + 1) * 0.5;
        delta[i] = 0.0;
    }

    i__1 = data_size - 2;
    ip1 = i__1 + 1;
    tau = 1.5e-2;
}