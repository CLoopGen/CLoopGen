#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *k;
real *alpha;
real *a;
real *beta;
real *c__;
integer a_dim1;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer l;
real temp;

static real alpha_data;
static real beta_data;
static integer k_data;
static integer a_dim1_data;
static integer c_dim1_data;
static integer i__1_data;

#define A_ROWS 1000
#define A_COLS 1000
#define C_ROWS 1000
#define C_COLS 1000

static real a_array[A_ROWS * A_COLS];
static real c_array[C_ROWS * C_COLS];

void init_vars() {
    alpha = &alpha_data;
    beta = &beta_data;
    k = &k_data;
    a = a_array;
    c__ = c_array;
    a_dim1 = a_dim1_data;
    c_dim1 = c_dim1_data;
    i__1 = i__1_data;

    alpha_data = 1.5f;
    beta_data = 1.0f;
    k_data = A_COLS;
    a_dim1_data = A_ROWS;
    c_dim1_data = C_ROWS;
    i__1_data = C_COLS;

    for (int i = 0; i < A_ROWS * A_COLS; ++i) {
        a_array[i] = sinf(i * 0.01f);
    }

    for (int i = 0; i < C_ROWS * C_COLS; ++i) {
        c_array[i] = cosf(i * 0.01f);
    }

    temp = 0.0f;
    i__ = 0;
    j = 0;
    l = 0;
    i__2 = 0;
    i__3 = 0;
}