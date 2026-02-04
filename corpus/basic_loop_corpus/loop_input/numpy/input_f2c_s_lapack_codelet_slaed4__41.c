#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *delta;
integer i__1;
integer j;
real eta;

void init_vars() {
    i__1 = 65536 * 4;  // Size to achieve ~0.01 sec runtime (adjustable)
    eta = 0.001f;
    delta = (real*)aligned_alloc(32, ((size_t)i__1 + 1) * sizeof(real));
    for (int i = 0; i <= i__1; ++i) {
        delta[i] = 1.0f;
    }
}