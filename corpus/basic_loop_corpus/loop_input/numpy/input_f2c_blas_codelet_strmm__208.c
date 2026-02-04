#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;
typedef int logical;

integer *m;
integer *n;
real *alpha;
real *a;
real *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer k;
real temp;
logical nounit;

static real *a_data = NULL;
static real *b_data = NULL;
static integer m_val, n_val;

void init_vars() {
    n_val = 500;
    m_val = 500;
    
    m = &m_val;
    n = &n_val;
    alpha = (real*)malloc(sizeof(real));
    *alpha = 1.23f;
    
    a_dim1 = n_val;
    b_dim1 = m_val;
    
    size_t a_size = (size_t)n_val * n_val;
    size_t b_size = (size_t)m_val * n_val;
    
    a_data = (real*)calloc(a_size, sizeof(real));
    b_data = (real*)calloc(b_size, sizeof(real));
    
    a = a_data;
    b = b_data;
    
    nounit = 1;
    
    for (int idx = 0; idx < n_val; ++idx) {
        a[idx + idx * a_dim1] = 2.0f + 0.1f * idx;
    }
    
    for (int i = 0; i < m_val; ++i) {
        for (int j = 0; j < n_val; ++j) {
            b[i + j * b_dim1] = (real)(i + j + 1) * 0.1f;
        }
    }
    
    for (int j = 1; j < n_val; ++j) {
        for (int k = 0; k < j; ++k) {
            if ((double)rand() / RAND_MAX < 0.3) {
                a[k + j * a_dim1] = (real)(rand()) / RAND_MAX * 2.0f - 1.0f;
            }
        }
    }
}