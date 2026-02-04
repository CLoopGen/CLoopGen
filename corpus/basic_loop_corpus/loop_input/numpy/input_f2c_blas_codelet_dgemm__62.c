#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *m;
integer *k;
doublereal *alpha;
doublereal *a;
doublereal *b;
doublereal *beta;
doublereal *c__;
integer a_dim1;
integer b_dim1;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer l;
doublereal temp;

static integer m_val;
static integer k_val;
static integer n_val;

void init_vars() {
    m_val = 512;
    k_val = 256;
    n_val = 256;
    
    m = &m_val;
    k = &k_val;
    alpha = (doublereal*)malloc(sizeof(doublereal));
    beta = (doublereal*)malloc(sizeof(doublereal));
    *alpha = 1.5;
    *beta = 0.5;
    
    a_dim1 = m_val;
    b_dim1 = k_val;
    c_dim1 = m_val;
    
    i__1 = n_val;
    i__2 = m_val;
    i__3 = m_val;
    
    size_t a_size = (size_t)m_val * k_val;
    size_t b_size = (size_t)k_val * n_val;
    size_t c_size = (size_t)m_val * n_val;
    
    a = (doublereal*)calloc(a_size, sizeof(doublereal));
    b = (doublereal*)calloc(b_size, sizeof(doublereal));
    c__ = (doublereal*)calloc(c_size, sizeof(doublereal));
    
    for (size_t i = 0; i < a_size; ++i) {
        a[i] = (doublereal)(i % 128) / 64.0;
    }
    for (size_t i = 0; i < b_size; ++i) {
        b[i] = (doublereal)((i + 1) % 97) / 48.0;
    }
    for (size_t i = 0; i < c_size; ++i) {
        c__[i] = (doublereal)(i % 256) / 128.0;
    }
}