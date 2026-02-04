#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer n_storage = 500;
integer k_storage = 400;
doublereal alpha_storage = 1.5;
doublereal beta_storage = 0.5;
integer a_dim1_storage = 400;
integer c_dim1_storage = 500;
integer i_1_storage = 500;

integer *n = &n_storage;
integer *k = &k_storage;
doublereal *alpha = &alpha_storage;
doublereal *beta = &beta_storage;
doublereal *a;
doublereal *c__;
integer a_dim1 = 400;
integer c_dim1 = 500;
integer i__1 = 500;
integer i__2;
integer i__3;
integer i__ = 0;
integer j = 0;
integer l = 0;
doublereal temp = 0.0;

void init_vars() {
    size_t a_size = (size_t)(k_storage + 1) * (a_dim1_storage + 1);
    size_t c_size = (size_t)(n_storage + 1) * (c_dim1_storage + 1);

    a = (doublereal*)calloc(a_size, sizeof(doublereal));
    c__ = (doublereal*)calloc(c_size, sizeof(doublereal));

    if (a == NULL || c__ == NULL) {
        exit(1);
    }

    for (int idx = 0; idx < a_size; ++idx) {
        a[idx] = (doublereal)(rand() % 100) / 10.0;
    }
    for (int idx = 0; idx < c_size; ++idx) {
        c__[idx] = (doublereal)(rand() % 100) / 10.0;
    }
}