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
doublereal t3;
doublereal t4;
doublereal t5;
doublereal t6;
doublereal t7;
doublereal v1;
doublereal v2;
doublereal v3;
doublereal v4;
doublereal v5;
doublereal v6;
doublereal v7;
doublereal sum;

void init_vars() {
    const size_t target_size_mb = 64;
    const size_t element_size = sizeof(doublereal);
    const size_t total_elements = (target_size_mb * 1024 * 1024) / element_size;

    c_dim1 = 8;
    i__1 = (integer)(total_elements / c_dim1);
    if (i__1 <= 0) i__1 = 1;

    size_t alloc_size = (i__1 + 1) * c_dim1 * sizeof(doublereal);
    c__ = (doublereal*)calloc(alloc_size / sizeof(doublereal), sizeof(doublereal));
    if (!c__) exit(1);

    t1 = 1.1; t2 = 1.2; t3 = 1.3; t4 = 1.4;
    t5 = 1.5; t6 = 1.6; t7 = 1.7;
    v1 = 0.1; v2 = 0.2; v3 = 0.3; v4 = 0.4;
    v5 = 0.5; v6 = 0.6; v7 = 0.7;
    sum = 0.0;
}