#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *m;
real *c__;
real *s;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
real temp;
real ctemp;
real stemp;

static integer m_storage;
static real *c_storage;
static real *s_storage;
static real *a_storage;

void init_vars() {
    // Set problem size to target ~0.01 seconds runtime
    // Empirical tuning: use matrix of size 2048 x 2048 for reasonable timing
    const integer n = 2048;
    const integer m_val = 2048;
    
    // Allocate arrays
    c_storage = (real*)calloc(n + 2, sizeof(real));
    s_storage = (real*)calloc(n + 2, sizeof(real));
    a_storage = (real*)calloc((m_val + 1) * (n + 2), sizeof(real));
    
    if (!c_storage || !s_storage || !a_storage) {
        exit(1);
    }
    
    // Initialize with non-trivial values so the condition (ctemp != 1.F || stemp != 0.F) triggers
    for (integer idx = 1; idx <= n; ++idx) {
        c_storage[idx] = (idx % 3 == 0) ? 1.0F : 0.8F;
        s_storage[idx] = (idx % 3 == 0) ? 0.0F : 0.6F;
    }
    
    // Initialize a matrix with non-zero values
    for (integer i = 1; i <= m_val; ++i) {
        for (integer j = 1; j <= n + 1; ++j) {
            a_storage[i + j * m_val] = (real)(i % 10 + j % 7);
        }
    }
    
    // Assign external pointers
    m = &m_storage;
    c__ = c_storage;
    s = s_storage;
    a = a_storage;
    a_dim1 = m_val;  // leading dimension
    
    // Set loop bounds
    i__1 = n;  // outer loop j from 1 to i__1
    i__2 = m_val; // inner loop i from 1 to i__2

    // Initialize working variables
    temp = 0.0F;
    ctemp = 0.0F;
    stemp = 0.0F;
    i__ = 1;
    j = 1;
}