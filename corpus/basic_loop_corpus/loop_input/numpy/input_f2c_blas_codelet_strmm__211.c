#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;
typedef int logical;

integer n_data = 512;
integer m_data = 512;
real alpha_data = 1.5f;
logical nounit_data = 1;

integer *m = &m_data;
integer *n = &n_data;
real *alpha = &alpha_data;
logical *nounit = &nounit_data;

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

void init_vars() {
    a_dim1 = *n;
    b_dim1 = *n;
    
    size_t a_size = (size_t)(*n) * (size_t)(*n);
    size_t b_size = (size_t)(*m) * (size_t)(*n);
    
    a = (real*)calloc(a_size, sizeof(real));
    b = (real*)calloc(b_size, sizeof(real));
    
    if (!a || !b) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    for (integer idx = 0; idx < a_size; ++idx) {
        a[idx] = sinf(idx % 100) * 0.1f;
    }
    
    for (integer idx = 0; idx < b_size; ++idx) {
        b[idx] = cosf(idx % 100) * 0.2f;
    }
    
    for (integer i = 1; i <= *n; ++i) {
        a[i + i * a_dim1] = 1.1f;
    }
}