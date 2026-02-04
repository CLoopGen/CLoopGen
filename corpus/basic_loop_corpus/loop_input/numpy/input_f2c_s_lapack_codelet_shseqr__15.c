#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *ihi;
real *h__;
real *wr;
real *wi;
integer h_dim1;
integer i__1;
integer i__;

static real *h__data = NULL;
static real *wr_data = NULL;
static real *wi_data = NULL;

void init_vars() {
    const integer n = 5000;

    h_dim1 = n;
    i__1 = n;
    ihi = (integer*)malloc(sizeof(integer));
    *ihi = n - 100;

    size_t total_size = (size_t)(n + 1) * (n + 1);
    h__data = (real*)calloc(total_size, sizeof(real));
    wr_data = (real*)calloc((n + 1), sizeof(real));
    wi_data = (real*)calloc((n + 1), sizeof(real));

    h__ = h__data;
    wr = wr_data;
    wi = wi_data;

    for (integer i = 1; i <= n; ++i) {
        for (integer j = 1; j <= n; ++j) {
            h__[i + j * h_dim1] = (real)(i * n + j);
        }
    }
}

__attribute__((destructor))
static void cleanup() {
    free(ihi);
    free(h__data);
    free(wr_data);
    free(wi_data);
}