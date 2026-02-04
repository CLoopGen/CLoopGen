#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *m;
real *a;
integer a_dim1;
integer i__1;
integer i__;
integer j;

static real a_data[65536];
static integer m_value = 256;

void init_vars() {
    m = &m_value;
    a = a_data;
    a_dim1 = 256;
    
    size_t total_size = a_dim1 * (*m);
    for (size_t idx = 0; idx < total_size; ++idx) {
        a[idx] = (real)(idx % 1000) + 0.5f;
    }
}