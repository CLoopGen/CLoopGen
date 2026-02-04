#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;
typedef double doublereal;

integer *m;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
real r__1;
real r__2;
real r__3;
integer i__;
integer j;
real value;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024 / sizeof(real))

static real a_data[TOTAL_ELEMENTS];
static integer m_value;
static integer n_value;

void init_vars() {
    m = &m_value;
    a = a_data;
    a_dim1 = n_value;

    n_value = (int)sqrt(TOTAL_ELEMENTS);
    m_value = TOTAL_ELEMENTS / n_value;
    while (m_value * n_value > TOTAL_ELEMENTS) {
        --m_value;
    }

    i__1 = n_value;
    value = 0.0f;

    for (int idx = 0; idx < m_value * n_value; ++idx) {
        a[idx] = (real)(fabs(rand() % 1000) * 0.01f);
    }
}