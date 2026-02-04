#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer n_val = 1024;
integer k_val = 512;
doublereal alpha_val = 1.5;
doublereal beta_val = 1.2;
integer a_dim1_val = 512;
integer c_dim1_val = 1024;
integer i__1_val = 1024;
integer i__2_val = 1024;
integer i__3_val = 1024;
integer i__ = 0;
integer j = 0;
integer l = 0;
doublereal temp = 0.0;

integer *n = &n_val;
integer *k = &k_val;
doublereal *alpha = &alpha_val;
doublereal *beta = &beta_val;
doublereal *a;
doublereal *c__;
integer a_dim1 = 512;
integer c_dim1 = 1024;
integer i__1 = 1024;
integer i__2 = 1024;
integer i__3 = 1024;

void init_vars() {
    size_t a_size = (size_t)(a_dim1_val + 1) * (k_val + 1);
    size_t c_size = (size_t)(c_dim1_val + 1) * (n_val + 1);

    a = (doublereal*)calloc(a_size, sizeof(doublereal));
    c__ = (doublereal*)calloc(c_size, sizeof(doublereal));

    if (!a || !c__) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < a_size; ++idx) {
        a[idx] = (doublereal)(rand() % 100) / 100.0;
    }
    for (int idx = 0; idx < c_size; ++idx) {
        c__[idx] = (doublereal)(rand() % 100) / 100.0;
    }
}