#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *k;
real *q;
real *dlamda;
real *w;
integer q_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

static real *q_data;
static real *dlamda_data;
static real *w_data;
static integer k_value;
static integer n_max;

void init_vars() {
    n_max = 2048;
    size_t q_size = (n_max + 1) * (n_max + 1) * sizeof(real);
    size_t dlamda_size = (n_max + 1) * sizeof(real);
    size_t w_size = (n_max + 1) * sizeof(real);

    q_data = (real *)calloc(1, q_size);
    dlamda_data = (real *)calloc(1, dlamda_size);
    w_data = (real *)calloc(1, w_size);

    if (!q_data || !dlamda_data || !w_data) {
        exit(1);
    }

    for (int idx = 1; idx <= n_max; ++idx) {
        dlamda_data[idx] = 1.0f + 0.1f * idx;
        w_data[idx] = 1.0f + 0.01f * idx;
        for (int jdx = 1; jdx <= n_max; ++jdx) {
            q_data[idx + jdx * n_max] = 0.5f + 0.01f * (idx - jdx);
        }
    }

    q = q_data;
    dlamda = dlamda_data;
    w = w_data;
    k = &k_value;
    q_dim1 = n_max;
    i__1 = n_max;
    k_value = n_max;
}