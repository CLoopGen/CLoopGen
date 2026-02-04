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
integer i__6;
singlecomplex q__1;
singlecomplex q__2;
integer i__;
integer j;
integer k;
singlecomplex temp;
logical nounit;

static singlecomplex alpha_data = {1.0f, 0.0f};
static integer m_data = 200;
static integer a_dim1_data = 200;
static integer b_dim1_data = 200;
static integer i__1_data = 200;

#define A_SIZE (200 * 200)
#define B_SIZE (200 * 200)

static singlecomplex a_data[A_SIZE];
static singlecomplex b_data[B_SIZE];

void init_vars() {
    m = &m_data;
    alpha = &alpha_data;
    a = a_data;
    b = b_data;
    a_dim1 = a_dim1_data;
    b_dim1 = b_dim1_data;
    i__1 = i__1_data;
    nounit = 1;

    for (int idx = 0; idx < A_SIZE; ++idx) {
        a_data[idx].r = (real)(idx % 7 + 1) / 7.0f;
        a_data[idx].i = (real)(idx % 5 + 1) / 5.0f;
    }

    for (int idx = 0; idx < B_SIZE; ++idx) {
        b_data[idx].r = (real)(idx % 13 + 1) / 13.0f;
        b_data[idx].i = (real)(idx % 11 + 1) / 11.0f;
    }
}