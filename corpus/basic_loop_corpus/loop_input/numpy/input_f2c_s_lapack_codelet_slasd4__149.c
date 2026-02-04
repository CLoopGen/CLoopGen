#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *delta;
real *work;
integer i__1;
integer j;
real eta;

void init_vars() {
    i__1 = 16777216; // 16 million elements ~16.8 MB of data per array (33.6 MB total), suitable for ~0.01 sec on modern CPU
    eta = 0.001f;

    delta = (real*)aligned_alloc(32, sizeof(real) * (i__1 + 1));
    work = (real*)aligned_alloc(32, sizeof(real) * (i__1 + 1));

    for (int i = 1; i <= i__1; ++i) {
        delta[i] = (real)(i % 1000) * 0.01f;
        work[i] = (real)(i % 1000) * 0.02f;
    }
}