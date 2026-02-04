#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *k;
real *alpha;
real *a;
real *b;
real *beta;
real *c__;
integer a_dim1;
integer b_dim1;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer l;
real temp1;
real temp2;

static real alpha_val = 1.5f;
static real beta_val = 0.5f;
static integer k_val = 1000;
static integer n = 1000;

static real *a_data;
static real *b_data;
static real *c_data;

void init_vars() {
    k = &k_val;
    alpha = &alpha_val;
    beta = &beta_val;

    a_dim1 = k_val;
    b_dim1 = k_val;
    c_dim1 = n;

    i__1 = n;

    a_data = (real*)calloc((k_val + 1) * (n + 1), sizeof(real));
    b_data = (real*)calloc((k_val + 1) * (n + 1), sizeof(real));
    c_data = (real*)calloc((n + 1) * (n + 1), sizeof(real));

    if (!a_data || !b_data || !c_data) {
        exit(1);
    }

    a = a_data - 1 - a_dim1; // 1-based indexing: a[l + i__ * a_dim1]
    b = b_data - 1 - b_dim1; // 1-based indexing: b[l + j * b_dim1]
    c__ = c_data - 1 - c_dim1; // 1-based indexing: c__[i__ + j * c_dim1]
}