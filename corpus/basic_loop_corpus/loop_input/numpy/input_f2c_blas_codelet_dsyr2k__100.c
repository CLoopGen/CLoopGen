#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer n_storage = 1000;
integer k_storage = 100;
doublereal alpha_storage = 1.5;
doublereal beta_storage = 1.0;

integer a_dim1 = 100;
integer b_dim1 = 100;
integer c_dim1 = 1000;

integer i__1 = 500;
integer i__2;
integer i__3;
integer i__;
integer j;
integer l;
doublereal temp1;
doublereal temp2;

doublereal *a = NULL;
doublereal *b = NULL;
doublereal *c__ = NULL;

integer *n = &n_storage;
integer *k = &k_storage;
doublereal *alpha = &alpha_storage;
doublereal *beta = &beta_storage;

void init_vars() {
    const size_t a_size = (100 + 1) * (100 + 1);
    const size_t b_size = (100 + 1) * (100 + 1);
    const size_t c_size = (1000 + 1) * (500 + 1);

    a = (doublereal*)calloc(a_size, sizeof(doublereal));
    b = (doublereal*)calloc(b_size, sizeof(doublereal));
    c__ = (doublereal*)calloc(c_size, sizeof(doublereal));

    if (!a || !b || !c__) {
        exit(1);
    }

    for (int idx = 0; idx < a_size; ++idx) {
        a[idx] = (doublereal)(rand() % 100) / 10.0;
    }
    for (int idx = 0; idx < b_size; ++idx) {
        b[idx] = (doublereal)(rand() % 100) / 10.0;
    }
    for (int idx = 0; idx < c_size; ++idx) {
        c__[idx] = (doublereal)(rand() % 100) / 10.0;
    }
}