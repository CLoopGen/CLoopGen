#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer m_storage = 200;
integer k_storage = 150;
integer a_dim1 = 200;
integer b_dim1 = 150;
integer c_dim1 = 200;
integer i__1 = 180;
integer i__2;
integer i__3;
integer i__;
integer j;
integer l;
doublereal alpha_storage = 1.5;
doublereal beta_storage = 0.5;
doublereal temp;

doublereal *a;
doublereal *b;
doublereal *c__;
integer *m = &m_storage;
integer *k = &k_storage;
doublereal *alpha = &alpha_storage;
doublereal *beta = &beta_storage;

void init_vars() {
    const size_t a_size = (size_t)(a_dim1 + 1) * (size_t)(m_storage + 1);
    const size_t b_size = (size_t)(b_dim1 + 1) * (size_t)(k_storage + 1);
    const size_t c_size = (size_t)(c_dim1 + 1) * (size_t)(m_storage + 1);

    a = (doublereal*)aligned_alloc(64, a_size * sizeof(doublereal));
    b = (doublereal*)aligned_alloc(64, b_size * sizeof(doublereal));
    c__ = (doublereal*)aligned_alloc(64, c_size * sizeof(doublereal));

    for (size_t i = 0; i < a_size; ++i) {
        a[i] = sin(i * 0.01);
    }
    for (size_t i = 0; i < b_size; ++i) {
        b[i] = cos(i * 0.01);
    }
    for (size_t i = 0; i < c_size; ++i) {
        c__[i] = 0.0;
    }
}