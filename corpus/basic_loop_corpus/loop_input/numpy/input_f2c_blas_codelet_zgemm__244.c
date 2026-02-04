#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer m_data = 200;
integer k_data = 150;
integer i_1_data = 180;

integer *m = &m_data;
integer *k = &k_data;
integer *i__1 = &i_1_data;

doublecomplex alpha_data = {1.5, -0.8};
doublecomplex beta_data = {0.7, -0.3};
doublecomplex temp_data;

doublecomplex *alpha = &alpha_data;
doublecomplex *beta = &beta_data;
doublecomplex temp;

integer a_dim1 = 200;
integer b_dim1 = 150;
integer c_dim1 = 200;

doublecomplex *a;
doublecomplex *b;
doublecomplex *c__;

integer i__, j, l;
integer i__2, i__3, i__4, i__5;
doublecomplex z__1, z__2, z__3;

void init_vars() {
    const size_t a_size = (size_t)a_dim1 * (size_t)m_data;
    const size_t b_size = (size_t)b_dim1 * (size_t)k_data;
    const size_t c_size = (size_t)c_dim1 * (size_t)i_1_data;

    a = (doublecomplex*)aligned_alloc(32, a_size * sizeof(doublecomplex));
    b = (doublecomplex*)aligned_alloc(32, b_size * sizeof(doublecomplex));
    c__ = (doublecomplex*)aligned_alloc(32, c_size * sizeof(doublecomplex));

    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < a_size; ++i) {
        a[i].r = sin((double)(rand() % 1000)) * 0.1;
        a[i].i = cos((double)(rand() % 1000)) * 0.1;
    }
    for (size_t i = 0; i < b_size; ++i) {
        b[i].r = cos((double)(rand() % 1000)) * 0.1;
        b[i].i = sin((double)(rand() % 1000)) * 0.1;
    }
    for (size_t i = 0; i < c_size; ++i) {
        c__[i].r = sin((double)(rand() % 500)) * 0.05;
        c__[i].i = cos((double)(rand() % 500)) * 0.05;
    }

    temp.r = 0.0;
    temp.i = 0.0;
    z__1.r = 0.0; z__1.i = 0.0;
    z__2.r = 0.0; z__2.i = 0.0;
    z__3.r = 0.0; z__3.i = 0.0;
    i__ = 0;
    j = 0;
    l = 0;
    i__2 = 0;
    i__3 = 0;
    i__4 = 0;
    i__5 = 0;
}