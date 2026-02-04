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

integer m_data = 128;
integer k_data = 128;
singlecomplex alpha_data = {1.5f, 0.5f};
singlecomplex beta_data = {0.8f, 0.2f};

integer a_dim1 = 128;
integer b_dim1 = 128;
integer c_dim1 = 128;

integer i__1 = 128;
integer i__2;
integer i__3;
integer i__4;
integer i__5;

singlecomplex q__1;
singlecomplex q__2;
singlecomplex q__3;

integer i__;
integer j;
integer l;
singlecomplex temp;

singlecomplex *a = NULL;
singlecomplex *b = NULL;
singlecomplex *c__ = NULL;

integer *m = &m_data;
integer *k = &k_data;
singlecomplex *alpha = &alpha_data;
singlecomplex *beta = &beta_data;

void init_vars() {
    const size_t size_a = (size_t)(m_data + 1) * (a_dim1 + 1);
    const size_t size_b = (size_t)(k_data + 1) * (b_dim1 + 1);
    const size_t size_c = (size_t)(m_data + 1) * (c_dim1 + 1);

    a = (singlecomplex*)calloc(size_a, sizeof(singlecomplex));
    b = (singlecomplex*)calloc(size_b, sizeof(singlecomplex));
    c__ = (singlecomplex*)calloc(size_c, sizeof(singlecomplex));

    if (!a || !b || !c__) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < size_a; ++idx) {
        a[idx].r = sinf(idx % 128) * 0.1f;
        a[idx].i = cosf(idx % 128) * 0.1f;
    }
    for (size_t idx = 0; idx < size_b; ++idx) {
        b[idx].r = cosf(idx % 128) * 0.1f;
        b[idx].i = sinf(idx % 128) * 0.1f;
    }
    for (size_t idx = 0; idx < size_c; ++idx) {
        c__[idx].r = 0.0f;
        c__[idx].i = 0.0f;
    }
}