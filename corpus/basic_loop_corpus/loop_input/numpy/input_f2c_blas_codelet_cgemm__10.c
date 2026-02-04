#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer m_data = 100;
integer k_data = 100;
singlecomplex alpha_data = {1.5f, 0.5f};
singlecomplex beta_data = {0.8f, 0.2f};

integer a_dim1 = 100;
integer b_dim1 = 100;
integer c_dim1 = 100;

integer i__1 = 100;

singlecomplex *a = NULL;
singlecomplex *b = NULL;
singlecomplex *c__ = NULL;

integer *m = &m_data;
integer *k = &k_data;
singlecomplex *alpha = &alpha_data;
singlecomplex *beta = &beta_data;

singlecomplex temp;

integer i__;
integer j;
integer l;

singlecomplex q__1;
singlecomplex q__2;
singlecomplex q__3;
integer i__2;
integer i__3;
integer i__4;
integer i__5;

void init_vars() {
    const int size_a = 101 * 101; // leading dimension padded
    const int size_b = 101 * 101;
    const int size_c = 101 * 101;

    a = (singlecomplex*)calloc(size_a, sizeof(singlecomplex));
    b = (singlecomplex*)calloc(size_b, sizeof(singlecomplex));
    c__ = (singlecomplex*)calloc(size_c, sizeof(singlecomplex));

    for (int i = 0; i < size_a; ++i) {
        a[i].r = sin(i * 0.1f);
        a[i].i = cos(i * 0.1f);
    }
    for (int i = 0; i < size_b; ++i) {
        b[i].r = cos(i * 0.07f);
        b[i].i = sin(i * 0.07f);
    }
    for (int i = 0; i < size_c; ++i) {
        c__[i].r = 0.1f * (i % 10);
        c__[i].i = 0.1f * (i % 7);
    }

    temp.r = 0.0f;
    temp.i = 0.0f;

    i__ = 0;
    j = 0;
    l = 0;

    q__1.r = 0.0f; q__1.i = 0.0f;
    q__2.r = 0.0f; q__2.i = 0.0f;
    q__3.r = 0.0f; q__3.i = 0.0f;

    i__2 = 0;
    i__3 = 0;
    i__4 = 0;
    i__5 = 0;
}