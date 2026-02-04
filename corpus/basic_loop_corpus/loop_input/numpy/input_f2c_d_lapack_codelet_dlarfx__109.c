#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *c__ = NULL;
integer c_dim1;
integer i__1;
integer j;
doublereal t1;
doublereal t2;
doublereal v1;
doublereal v2;
doublereal sum;

void init_vars() {
    const size_t data_size = 128 << 20; // 128 MB
    c_dim1 = data_size / sizeof(doublereal) / 3; // Ensure two columns exist: c_dim1 and 2*c_dim1
    i__1 = c_dim1; // Loop over all rows in bounds

    if (c__) free(c__);
    c__ = (doublereal*)aligned_alloc(64, data_size);
    if (!c__) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    t1 = 1.5;
    t2 = 2.5;
    v1 = 0.8;
    v2 = 1.2;
    sum = 0.0;

    for (integer i = 0; i < data_size / sizeof(doublereal); ++i) {
        c__[i] = (doublereal)(i & 0xFF);
    }
}