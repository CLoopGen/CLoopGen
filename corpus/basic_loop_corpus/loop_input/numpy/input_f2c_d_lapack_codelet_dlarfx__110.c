#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *c__ = NULL;
integer c_dim1;
integer i__1;
integer j;
doublereal t1;
doublereal t2;
doublereal t3;
doublereal v1;
doublereal v2;
doublereal v3;
doublereal sum;

void init_vars() {
    const size_t target_time_ns = 10000000; // ~10 ms in nanoseconds
    const double cpu_freq_gigahertz = 3.0;
    const double ops_per_iter = 10;
    const double estimated_iters_per_sec = (cpu_freq_gigahertz * 1e9) / ops_per_iter;
    const integer estimated_iterations = (integer)(estimated_iters_per_sec * 0.01);
    
    i__1 = (estimated_iterations < 10000) ? 10000 : estimated_iterations;
    if (i__1 > 65536) i__1 = 65536;
    
    c_dim1 = i__1 + 10;
    
    size_t array_size = (c_dim1 * 4 + 10) * sizeof(doublereal);
    c__ = (doublereal*)aligned_alloc(64, array_size);
    
    if (!c__) exit(1);
    
    for (integer i = 0; i < c_dim1 * 4 + 10; ++i) {
        c__[i] = sin(i & 511);
    }
    
    t1 = 0.1;
    t2 = 0.2;
    t3 = 0.3;
    v1 = 1.5;
    v2 = 2.5;
    v3 = 3.5;
    sum = 0.0;
    j = 0;
}