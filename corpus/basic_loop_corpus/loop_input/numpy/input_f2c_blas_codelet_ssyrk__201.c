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

static real alpha_val = 1.5f;
static real beta_val = 0.8f;
static integer k_val = 500;
static integer size_a = 500;
static integer size_c = 500;

static real *a_data;
static real *c_data;

void init_vars() {
    const double target_time_estimate_per_operation = 1e-7; 
    const int estimated_operations = size_a * size_a * k_val / 2; 
    const double estimated_time = estimated_operations * target_time_estimate_per_operation;

    if (estimated_time < 0.008 || estimated_time > 0.02) {
        size_a = 400;
        size_c = 400;
        k_val = 400;
    }

    a_dim1 = size_a;
    c_dim1 = size_c;
    i__1 = size_c;

    k = &k_val;
    alpha = &alpha_val;
    beta = &beta_val;

    a_data = (real*)calloc((size_a + 1) * (a_dim1 + 1), sizeof(real));
    c_data = (real*)calloc((size_c + 1) * (c_dim1 + 1), sizeof(real));

    a = a_data;
    c__ = c_data;

    for (int idx = 0; idx <= size_a; ++idx) {
        for (int jdx = 0; jdx <= a_dim1; ++jdx) {
            a[idx + jdx * a_dim1] = (real)(drand48() * 2.0 - 1.0);
        }
    }

    for (int idx = 0; idx <= size_c; ++idx) {
        for (int jdx = 0; jdx <= c_dim1; ++jdx) {
            c__[idx + jdx * c_dim1] = (real)(drand48() * 2.0 - 1.0);
        }
    }

    temp = 0.0f;
}