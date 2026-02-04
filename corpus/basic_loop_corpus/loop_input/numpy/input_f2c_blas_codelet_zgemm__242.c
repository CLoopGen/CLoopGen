#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer m_storage = 200;
integer k_storage = 150;
integer i__1_storage = 180;

integer *m = &m_storage;
integer *k = &k_storage;
integer *i__1 = &i__1_storage;

doublecomplex alpha_storage = {1.5, 0.5};
doublecomplex beta_storage = {1.0, 0.2};
doublecomplex *alpha = &alpha_storage;
doublecomplex *beta = &beta_storage;

integer a_dim1 = 200;
integer b_dim1 = 150;
integer c_dim1 = 200;

doublecomplex *a = NULL;
doublecomplex *b = NULL;
doublecomplex *c__ = NULL;

integer i__2;
integer i__3;
integer i__4;
integer i__5;
doublecomplex z__1;
doublecomplex z__2;
doublecomplex z__3;
integer i__;
integer j;
integer l;
doublecomplex temp;

void init_vars() {
    const size_t a_size = (size_t)(a_dim1) * (size_t)(*m);
    const size_t b_size = (size_t)(b_dim1) * (size_t)(*k);
    const size_t c_size = (size_t)(c_dim1) * (size_t)(*m);

    a = (doublecomplex*)calloc(a_size, sizeof(doublecomplex));
    b = (doublecomplex*)calloc(b_size, sizeof(doublecomplex));
    c__ = (doublecomplex*)calloc(c_size, sizeof(doublecomplex));

    if (!a || !b || !c__) {
        exit(1);
    }

    for (size_t idx = 0; idx < a_size; ++idx) {
        a[idx].r = (doublereal)(idx % 7) / 7.0;
        a[idx].i = (doublereal)(idx % 5) / 5.0;
    }

    for (size_t idx = 0; idx < b_size; ++idx) {
        b[idx].r = (doublereal)(idx % 6) / 6.0;
        b[idx].i = (doublereal)(idx % 4) / 4.0;
    }

    for (size_t idx = 0; idx < c_size; ++idx) {
        c__[idx].r = (doublereal)(idx % 3) / 3.0;
        c__[idx].i = (doublereal)(idx % 2) / 2.0;
    }
}