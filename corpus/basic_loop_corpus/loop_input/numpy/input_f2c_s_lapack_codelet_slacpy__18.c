#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;
typedef float real;

integer *m;
real *a;
real *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

static real *a_data;
static real *b_data;
static integer m_value;
static integer n_value;

void init_vars() {
    n_value = 4096;  
    m_value = 64;   

    i__1 = n_value;
    a_dim1 = m_value;
    b_dim1 = m_value;

    posix_memalign((void**)&a_data, 32, (size_t)m_value * n_value * sizeof(real));
    posix_memalign((void**)&b_data, 32, (size_t)m_value * n_value * sizeof(real));

    a = a_data;
    b = b_data;

    m = &m_value;

    for (integer idx = 0; idx < m_value * n_value; ++idx) {
        a_data[idx] = (real)(idx % 1000) / 100.0f;
        b_data[idx] = 0.0f;
    }
}