#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer n_data = 500;
integer k_data = 400;
doublereal alpha_data = 1.2;
doublereal beta_data = 0.8;

integer a_dim1 = 500;
integer b_dim1 = 500;
integer c_dim1 = 500;

integer i__1 = 500;
integer i__2;
integer i__3;
integer i__ = 1;
integer j = 1;
integer l = 1;
doublereal temp1 = 0.0;
doublereal temp2 = 0.0;

integer *n = &n_data;
integer *k = &k_data;
doublereal *alpha = &alpha_data;
doublereal *beta = &beta_data;
doublereal *a;
doublereal *b;
doublereal *c__;

void init_vars() {
    size_t a_size = (size_t)a_dim1 * (size_t)n_data * sizeof(doublereal);
    size_t b_size = (size_t)b_dim1 * (size_t)k_data * sizeof(doublereal);
    size_t c_size = (size_t)c_dim1 * (size_t)n_data * sizeof(doublereal);

    a = (doublereal *)calloc(1, a_size);
    b = (doublereal *)calloc(1, b_size);
    c__ = (doublereal *)calloc(1, c_size);

    if (!a || !b || !c__) {
        exit(1);
    }

    for (int i = 0; i < a_dim1 * n_data; ++i) {
        a[i] = (doublereal)(i % 100) / 100.0;
    }
    for (int i = 0; i < b_dim1 * k_data; ++i) {
        b[i] = (doublereal)(i % 100) / 100.0;
    }
    for (int i = 0; i < c_dim1 * n_data; ++i) {
        c__[i] = (doublereal)(i % 100) / 100.0;
    }
}