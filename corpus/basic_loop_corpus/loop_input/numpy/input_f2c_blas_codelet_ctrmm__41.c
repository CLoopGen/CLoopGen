#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int logical;

integer *m;
singlecomplex *alpha;
singlecomplex *a;
singlecomplex *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
singlecomplex q__1;
singlecomplex q__2;
integer i__;
integer j;
integer k;
singlecomplex temp;
logical nounit;

static singlecomplex alpha_data = {1.0f, 0.0f};
static integer m_data = 512;
static integer a_dim1_data = 512;
static integer b_dim1_data = 512;
static integer i__1_data = 512;

static singlecomplex *a_data;
static singlecomplex *b_data;

void init_vars() {
    m = &m_data;
    alpha = &alpha_data;
    a_dim1 = a_dim1_data;
    b_dim1 = b_dim1_data;
    i__1 = i__1_data;
    nounit = 1;

    a_data = (singlecomplex*)aligned_alloc(64, sizeof(singlecomplex) * m_data * a_dim1_data);
    b_data = (singlecomplex*)aligned_alloc(64, sizeof(singlecomplex) * m_data * b_dim1_data);

    if (!a_data || !b_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    a = a_data;
    b = b_data;

    for (int idx = 0; idx < m_data * a_dim1_data; ++idx) {
        a_data[idx].r = (real)(idx % 7 + 1) / 7.0f;
        a_data[idx].i = (real)(idx % 5 + 1) / 5.0f;
    }

    for (int idx = 0; idx < m_data * b_dim1_data; ++idx) {
        b_data[idx].r = (real)(idx % 3 + 1) / 3.0f;
        b_data[idx].i = (real)(idx % 2 + 1) / 2.0f;
    }

    temp.r = 0.0f;
    temp.i = 0.0f;
}