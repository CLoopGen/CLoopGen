#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
doublereal *delta = NULL;
doublereal *work = NULL;
integer i__1 = 0;
integer j = 0;
integer ip1 = 0;
doublereal eta = 0.0;

void init_vars() {
    size_t data_size = 1 << 24; // ~16 million elements, roughly 128MB for three double arrays
    i__1 = (integer)(data_size / sizeof(doublereal)) - 1; // ensure ip1 is in bounds
    ip1 = i__1 + 1;

    d__ = (doublereal*)calloc(data_size, sizeof(doublereal));
    work = (doublereal*)calloc(data_size, sizeof(doublereal));
    delta = (doublereal*)calloc(data_size, sizeof(doublereal));

    eta = 1.5;

    if (!d__ || !work || !delta) {
        exit(1);
    }
}