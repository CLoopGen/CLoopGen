#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

doublecomplex *beta;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;

void init_vars() {
    const size_t target_time_ns = 10000000; // 0.01 seconds in nanoseconds
    const double cpu_freq_giga = 3.0; // Assume 3 GHz for estimation
    const long long operations_per_iter = 5; // Estimate of CPU ops per loop iteration

    // Estimated iterations to achieve ~0.01s runtime
    long long estimated_iters = (target_time_ns / 1e9) * cpu_freq_giga * 1e9 / operations_per_iter;
    long long n = (long long)sqrt(estimated_iters);
    if (n < 100) n = 100;
    else if (n > 100000) n = 100000;

    i__1 = (integer)n;
    a_dim1 = (integer)n;

    beta = (doublecomplex*)malloc(sizeof(doublecomplex));
    if (!beta) exit(1);
    beta->r = 1.618;
    beta->i = 0.577;

    size_t a_size = ((size_t)n + 1) * ((size_t)n + 1);
    a = (doublecomplex*)calloc(a_size, sizeof(doublecomplex));
    if (!a) exit(1);

    i__ = 0;
    i__2 = 0;
}