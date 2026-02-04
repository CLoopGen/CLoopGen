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

integer *m;
singlecomplex *c__;
real *rwork;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;
integer l;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Empirical tuning: aim for total elements around 1M to 16M
    const int m_val = 2048;          // rows
    const int n_val = 1024;          // columns, related to i__1
    const int l_val = 0;             // offset base

    // Allocate and initialize m
    m = (integer*)malloc(sizeof(integer));
    *m = m_val;

    // Initialize loop bounds
    i__1 = n_val;                    // j from 1 to n_val
    c_dim1 = m_val;                  // leading dimension of c__
    l = l_val;

    // Total elements in c__: (m_val+1) * (n_val+1) to allow 1-based indexing
    c__ = (singlecomplex*)calloc((m_val + 1) * (n_val + 1), sizeof(singlecomplex));

    // rwork size: l + (j-1)*m + i - 1, max when j=n_val, i=m_val
    // index = l + (n_val-1)*m_val + m_val - 1 = l + n_val*m_val - 1
    // so we need at least l + n_val * m_val elements
    const int rwork_size = l_val + n_val * m_val;
    rwork = (real*)malloc(rwork_size * sizeof(real));

    // Initialize rwork with dummy data
    for (int idx = 0; idx < rwork_size; ++idx) {
        rwork[idx] = (real)(idx % 100) / 100.0f;
    }

    // Initialize temporary indices to safe values (will be overwritten in loop)
    i__2 = *m;
    i__3 = 0;
    i__4 = 0;
}