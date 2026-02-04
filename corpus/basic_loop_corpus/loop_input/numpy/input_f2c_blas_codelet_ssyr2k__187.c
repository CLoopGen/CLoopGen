#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;

real *c__ = NULL;
integer c_dim1 = 0;
integer i__1 = 0;
integer i__2 = 0;
integer i__ = 0;
integer j = 0;

void init_vars() {
    const double estimated_time_seconds = 0.01;
    const double ops_per_second = 1e9;
    const double estimated_ops = estimated_time_seconds * ops_per_second;

    int n = (int)sqrt(estimated_ops);
    if (n < 1) n = 1;

    c_dim1 = n;
    i__1 = n;

    size_t total_size = (size_t)(n + 1) * (size_t)(n + 1);
    c__ = (real*)calloc(total_size, sizeof(real));
    if (!c__) {
        exit(1);
    }
}