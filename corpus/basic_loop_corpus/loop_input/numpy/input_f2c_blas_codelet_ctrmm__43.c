#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int logical;

integer *m;
integer *n;
singlecomplex *alpha;
singlecomplex *a;
singlecomplex *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
integer i__6;
singlecomplex q__1;
singlecomplex q__2;
integer i__;
integer j;
integer k;
singlecomplex temp;
logical nounit;

static singlecomplex *a_data;
static singlecomplex *b_data;
static integer m_val;
static integer n_val;

void init_vars() {
    m_val = 512;
    n_val = 512;
    
    m = &m_val;
    n = &n_val;
    
    a_dim1 = m_val;
    b_dim1 = m_val;
    
    i__1 = n_val;
    
    alpha = (singlecomplex*)malloc(sizeof(singlecomplex));
    alpha->r = 1.5f;
    alpha->i = 0.5f;
    
    size_t a_size = (size_t)a_dim1 * (size_t)n_val;
    size_t b_size = (size_t)b_dim1 * (size_t)n_val;
    
    a_data = (singlecomplex*)calloc(a_size, sizeof(singlecomplex));
    b_data = (singlecomplex*)calloc(b_size, sizeof(singlecomplex));
    
    a = a_data;
    b = b_data;
    
    for (int i = 0; i < m_val; ++i) {
        for (int j = 0; j < n_val; ++j) {
            if (i >= j) {
                a[i + j * a_dim1].r = sinf((i + 1) * 0.1f) * cosf((j + 1) * 0.1f);
                a[i + j * a_dim1].i = cosf((i + 1) * 0.1f) * sinf((j + 1) * 0.1f);
            }
            b[i + j * b_dim1].r = 1.0f / ((i + j + 2) * 1.0f);
            b[i + j * b_dim1].i = 0.1f * (i - j) / (i + j + 2);
        }
    }
    
    nounit = 1;
    
    temp.r = 0.0f;
    temp.i = 0.0f;
    
    q__1.r = 0.0f;
    q__1.i = 0.0f;
    q__2.r = 0.0f;
    q__2.i = 0.0f;
}