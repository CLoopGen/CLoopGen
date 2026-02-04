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

integer m_val = 512;
integer k_val = 512;
doublereal alpha_val[2] = {1.0, 1.0};
doublereal beta_val[2] = {1.0, 0.0};
integer a_dim1_val = 512;
integer b_dim1_val = 512;
integer c_dim1_val = 512;
integer i__1_val = 512;
integer i__2_val = 512;
integer i__3_val = 512;
integer i__4_val = 512;
integer i__5_val = 512;
integer i__6_val = 512;

doublecomplex z__1_val;
doublecomplex z__2_val;
integer i_val;
integer j_val;
integer l_val;
doublecomplex temp_val;

integer *m = &m_val;
integer *k = &k_val;
doublecomplex *alpha = (doublecomplex*)alpha_val;
doublecomplex *beta = (doublecomplex*)beta_val;
integer a_dim1 = 512;
integer b_dim1 = 512;
integer c_dim1 = 512;
integer i__1 = 512;
integer i__2 = 512;
integer i__3 = 512;
integer i__4 = 512;
integer i__5 = 512;
integer i__6 = 512;
doublecomplex z__1;
doublecomplex z__2;
integer i__;
integer j;
integer l;
doublecomplex temp;

doublecomplex *a = NULL;
doublecomplex *b = NULL;
doublecomplex *c__ = NULL;

void init_vars() {
    size_t a_size = (size_t)a_dim1 * (size_t)m_val;
    size_t b_size = (size_t)b_dim1 * (size_t)k_val;
    size_t c_size = (size_t)c_dim1 * (size_t)m_val;

    a = (doublecomplex*)calloc(a_size, sizeof(doublecomplex));
    b = (doublecomplex*)calloc(b_size, sizeof(doublecomplex));
    c__ = (doublecomplex*)calloc(c_size, sizeof(doublecomplex));

    if (!a || !b || !c__) {
        exit(1);
    }

    for (size_t idx = 0; idx < a_size; ++idx) {
        a[idx].r = (doublereal)(idx % 128) / 64.0;
        a[idx].i = 0.0;
    }

    for (size_t idx = 0; idx < b_size; ++idx) {
        b[idx].r = (doublereal)(idx % 128) / 64.0;
        b[idx].i = 0.0;
    }

    for (size_t idx = 0; idx < c_size; ++idx) {
        c__[idx].r = (doublereal)(idx % 256) / 128.0;
        c__[idx].i = 0.0;
    }

    i__1 = m_val;
}