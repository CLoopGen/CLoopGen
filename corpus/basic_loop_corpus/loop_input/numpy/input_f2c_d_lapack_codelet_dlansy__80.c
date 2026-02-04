#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *a;
integer a_dim1;
integer i__1;
integer i__2;
doublereal d__1;
doublereal d__2;
doublereal d__3;
integer i__;
integer j;
doublereal value;

void init_vars() {
    const size_t target_size_bytes = 64 * 1024 * 1024; // ~64 MB for sufficient runtime (~0.01s)
    a_dim1 = (integer)sqrt(target_size_bytes / sizeof(doublereal));
    i__1 = a_dim1 > 1000 ? 1000 : a_dim1; // bound column loop to avoid excessive iterations

    a = (doublereal*)calloc(a_dim1 * a_dim1, sizeof(doublereal));
    if (!a) exit(1);

    for (integer idx = 0; idx < a_dim1 * a_dim1; ++idx) {
        a[idx] = sin(idx % 127); // initialize with smooth pseudo-random values
    }

    value = 0.0;
    i__ = 1;
    j = 1;
    d__1 = 0.0;
    d__2 = 0.0;
    d__3 = 0.0;
}