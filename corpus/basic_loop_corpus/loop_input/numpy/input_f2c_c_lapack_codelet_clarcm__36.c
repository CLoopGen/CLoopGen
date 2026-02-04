#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
singlecomplex *b;
real *rwork;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    // Set problem size to achieve ~0.01 sec runtime
    // Based on typical performance, use m ≈ 8000, i__1 ≈ 8000 → total iterations ~64e6
    // This accesses about 200MB of data (assuming sizeof(singlecomplex) = 8, real = 4)
    *m = 8000;
    i__1 = 8000;
    b_dim1 = *m;

    // Allocate arrays with proper sizes
    b = (singlecomplex*)calloc((*m) * i__1 + 1, sizeof(singlecomplex));
    rwork = (real*)calloc((*m) * i__1, sizeof(real));

    // Initialize b with non-zero values to avoid compiler optimization removing loads
    for (int idx = 0; idx < (*m) * i__1; ++idx) {
        b[idx].r = (real)(idx % 100) * 0.5f;
        b[idx].i = (real)(idx % 101) * 0.25f;
    }
}

// Force definitions to be available
static integer _m_storage = 8000;
static real _dummy_align;

// Assign pointers to valid storage
integer* m = &_m_storage;