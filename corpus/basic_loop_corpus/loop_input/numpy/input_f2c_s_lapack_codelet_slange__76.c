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
real *work;
integer a_dim1;
integer i__1;
integer i__2;
real r__1;
integer i__;
integer j;

static integer m_val;
static integer a_size;
static integer work_size;

void init_vars() {
    // Set problem size to achieve roughly 0.01 seconds runtime
    // Based on typical performance, use M ~ 8000, N ~ 4000 for moderate compute load
    m_val = 8000;
    i__1 = 4000;  // j loops from 1 to i__1
    a_dim1 = m_val; // leading dimension of matrix a

    // Total size of a is m_val * i__1
    a_size = m_val * i__1;
    work_size = m_val;

    // Allocate arrays
    a = (real*)calloc(a_size, sizeof(real));
    work = (real*)calloc(work_size, sizeof(real));
    m = &m_val;

    // Initialize a with small random values to avoid zero-only computation
    for (integer idx = 0; idx < a_size; ++idx) {
        a[idx] = (real)(rand() % 2000) / 1000.0f - 1.0f; // values in [-1.0, 1.0]
    }

    // Initialize work to zero (already done by calloc, but be explicit)
    for (integer idx = 0; idx < work_size; ++idx) {
        work[idx] = 0.0f;
    }

    // Initialize scalars used in loop
    r__1 = 0.0f;
    i__2 = 0;
    i__ = 0;
    j = 0;
}