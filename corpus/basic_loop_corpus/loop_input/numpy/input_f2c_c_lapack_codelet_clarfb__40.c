#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *c__ = NULL;
singlecomplex *work = NULL;
integer c_dim1;
integer work_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
singlecomplex q__1;
integer i__;
integer j;
integer lastc;

void init_vars() {
    // Set problem dimensions to achieve ~0.01s runtime
    // Empirical tuning: aim for moderate size that avoids segfaults and fits typical L2/L3 cache behavior
    i__1 = 1000;          // j from 1 to 1000
    lastc = 1000;         // i from 1 to 1000
    c_dim1 = 1000;
    work_dim1 = 1000;

    // Allocate arrays with proper bounds: indices go up to lastc + j*c_dim1, max index ~1000 + 1000*1000 = 1e6+1
    // So we need at least (lastc) * (i__1) elements, stored column-major? -> allocate as 2D arrays flattened
    size_t total_c_size = (size_t)(lastc + 1) * (i__1 + 1);  // 1-indexed, so use +1
    size_t total_work_size = (size_t)(lastc + 1) * (i__1 + 1);

    c__ = (singlecomplex*)calloc(total_c_size, sizeof(singlecomplex));
    work = (singlecomplex*)calloc(total_work_size, sizeof(singlecomplex));

    if (!c__ || !work) {
        exit(1);
    }

    // Initialize with meaningful data to avoid undefined behavior in computation
    for (size_t idx = 0; idx < total_c_size; ++idx) {
        c__[idx].r = 1.0f;
        c__[idx].i = 0.5f;
        work[idx].r = 0.3f;
        work[idx].i = 0.1f;
    }
}