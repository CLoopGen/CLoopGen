#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *c__ = NULL;
integer c_dim1 = 0;
integer i__1 = 0;
integer i__2 = 0;
integer i__ = 0;
integer j = 0;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // Aim for ~64 MB of data
    const integer n = (integer)sqrt(target_bytes / sizeof(doublereal)); // Estimate square matrix size
    c_dim1 = n;
    i__1 = n;

    c__ = (doublereal*)calloc((size_t)(n + 1) * (n + 1), sizeof(doublereal));
    if (!c__) {
        exit(1);
    }
}