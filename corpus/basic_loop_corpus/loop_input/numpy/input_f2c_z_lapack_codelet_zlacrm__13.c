#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *m;
doublecomplex *c__;
doublereal *rwork;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
doublereal d__1;
doublecomplex z__1;
integer i__;
integer j;
integer l;

static integer m_val;
static integer c_dim1_val;
static integer i__1_val;
static integer l_val;
static size_t c_size;
static size_t rwork_size;

void init_vars() {
    // Set reasonable problem size to achieve ~0.01s runtime
    // Based on typical performance, aim for several million elements
    i__1_val = 2000;    // j from 1 to 2000
    m_val = 1000;       // i from 1 to 1000
    c_dim1_val = m_val; // leading dimension of matrix c__
    l_val = m_val;      // l is at least m

    // Initialize external loop bounds
    i__1 = i__1_val;
    m = &m_val;
    c_dim1 = c_dim1_val;
    l = l_val;

    // Compute sizes
    c_size = (m_val + 1) * (i__1_val + 1); // 1-based indexing: indices up to m_val and i__1_val
    rwork_size = l_val + (i__1_val - 1) * m_val + m_val; // max index: l + (j-1)*m + i - 1, j<=i1, i<=m

    // Allocate with padding for safety
    c__ = (doublecomplex*)calloc(c_size + 100, sizeof(doublecomplex));
    rwork = (doublereal*)calloc(rwork_size + 100, sizeof(doublereal));

    // Initialize arrays to avoid NaN or extreme values
    for (size_t idx = 0; idx < c_size + 100; ++idx) {
        c__[idx].r = 1.0;
        c__[idx].i = 0.0;
    }
    for (size_t idx = 0; idx < rwork_size + 100; ++idx) {
        rwork[idx] = 0.5;
    }

    // Ensure no out-of-bounds in loop:
    // Max access: i__ + j*c_dim1 <= m_val + i__1_val * c_dim1_val
    // We set c_dim1_val = m_val, so max index is m_val + i__1_val * m_val
    // Our allocation c_size = (m_val+1)*(i__1_val+1) >= m_val + i__1_val*m_val for m_val,i__1_val >= 1

    // For rwork: index = l + (j-1)*m + i - 1 <= l_val + (i__1_val-1)*m_val + m_val - 1
    // = l_val + i__1_val*m_val - 1
    // Our rwork_size = l_val + i__1_val*m_val -> safe
}