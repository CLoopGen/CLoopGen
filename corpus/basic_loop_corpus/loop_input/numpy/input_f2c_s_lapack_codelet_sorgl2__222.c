#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *m;
integer *k;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer j;
integer l;

static real *a_data;
static integer m_val;
static integer k_val;

void init_vars() {
    m_val = 5000;
    k_val = 1000;
    i__1 = 2000;

    m = &m_val;
    k = &k_val;

    a_dim1 = 5000;

    size_t a_size = (size_t)(a_dim1 + 1) * (i__1 + 1);
    a_data = (real*)calloc(a_size, sizeof(real));
    if (!a_data) {
        exit(1);
    }
    a = a_data - 1 - a_dim1;
}