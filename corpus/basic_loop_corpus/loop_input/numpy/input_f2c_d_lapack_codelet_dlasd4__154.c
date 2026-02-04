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
doublereal dpsi = 0.0;
doublereal temp = 0.0;
doublereal erretm = 0.0;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of total data (adjust for ~0.01s runtime)
    const size_t array_len = data_size / (3 * sizeof(doublereal)); // Three arrays: z__, delta, work

    z__ = (doublereal*)calloc(array_len, sizeof(doublereal));
    delta = (doublereal*)calloc(array_len, sizeof(doublereal));
    work = (doublereal*)calloc(array_len, sizeof(doublereal));

    for (size_t i = 0; i < array_len; ++i) {
        z__[i] = (doublereal)(i + 1);
        delta[i] = (doublereal)(i % 128 + 1);
        work[i] = (doublereal)(i % 256 + 1);
    }

    i__1 = (integer)(array_len - 1); // Ensure j <= i__1 stays in bounds
    psi = 0.0;
    dpsi = 0.0;
    erretm = 0.0;
}