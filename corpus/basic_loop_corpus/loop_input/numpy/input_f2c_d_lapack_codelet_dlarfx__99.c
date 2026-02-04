#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *c__ = NULL;
integer c_dim1;
integer i__1;
integer j;
doublereal t1;
doublereal t2;
doublereal v1;
doublereal v2;
doublereal sum;

void init_vars() {
    const size_t target_time_ns = 10000000; // ~10 ms in nanoseconds
    const double cpu_freq_giga = 3.0; // Assume 3 GHz typical modern CPU
    const double ops_per_iter = 10; // Rough estimate of operations per loop iteration
    const double estimated_iters = target_time_ns * 1e-9 * cpu_freq_giga * 1e9 / ops_per_iter;
    
    // Derive problem size
    i__1 = (integer)(estimated_iters);
    if (i__1 < 1000) i__1 = 1000;
    
    c_dim1 = 4; // Sufficient to allow access at indices j*c_dim1+1 and j*c_dim1+2
    
    // Allocate matrix c__ with dimensions [c_dim1 x i__1] -> accessed as column-major
    c__ = (doublereal*)calloc(i__1 * c_dim1, sizeof(doublereal));
    if (!c__) {
        exit(1);
    }
    
    // Initialize computation variables
    t1 = 0.75;
    t2 = 0.25;
    v1 = 1.5;
    v2 = -0.5;
    sum = 0.0;
    j = 0;
}