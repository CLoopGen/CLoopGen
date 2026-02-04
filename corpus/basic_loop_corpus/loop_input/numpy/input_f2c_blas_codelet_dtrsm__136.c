#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer *m;
integer *n;
doublereal *alpha;
doublereal *a;
doublereal *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer k;
doublereal temp;
logical nounit;

static doublereal* a_data = NULL;
static doublereal* b_data = NULL;
static integer m_val;
static integer n_val;

void init_vars() {
    m_val = 512;
    n_val = 512;
    
    m = &m_val;
    n = &n_val;
    alpha = (doublereal*)malloc(sizeof(doublereal));
    *alpha = 1.2;
    
    a_dim1 = m_val;
    b_dim1 = m_val;
    i__1 = (m_val < n_val) ? m_val : n_val;
    
    a_data = (doublereal*)calloc(m_val * n_val, sizeof(doublereal));
    b_data = (doublereal*)calloc(m_val * n_val, sizeof(doublereal));
    
    a = a_data;
    b = b_data;
    
    nounit = 1;
    temp = 0.0;
    i__ = 0;
    j = 0;
    k = 0;
    i__2 = 0;
    i__3 = 0;
    
    for (integer i = 0; i < m_val; ++i) {
        for (integer j = 0; j < n_val; ++j) {
            a[i + j * a_dim1] = (i == j) ? 2.0 + 0.1 * rand() / RAND_MAX : 
                                (j < i) ? 0.1 * rand() / RAND_MAX : 0.0;
            b[i + j * b_dim1] = 1.0 + 0.1 * rand() / RAND_MAX;
        }
    }
}