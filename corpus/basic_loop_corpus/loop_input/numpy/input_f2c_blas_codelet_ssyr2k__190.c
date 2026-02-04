#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *n;
real *beta;
real *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

real *c_data;
integer n_val;

void init_vars() {
    const double target_time = 0.01; 
    const double mflops_est = 1e8; 
    const double ops_per_inner_iter = 2; 

    double estimated_ops = target_time * mflops_est;
    integer approx_elements = (integer)ceil(estimated_ops / ops_per_inner_iter);
    n_val = (integer)sqrt((double)approx_elements) + 1;
    
    i__1 = n_val; 
    *n = n_val;

    c_dim1 = n_val;
    size_t c_size = (size_t)(n_val + 1) * (n_val + 1);
    c_data = (real *)calloc(c_size, sizeof(real));
    if (!c_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < c_size; ++idx) {
        c_data[idx] = (real)(rand() / (double)RAND_MAX);
    }

    c__ = c_data;

    beta = (real *)malloc(sizeof(real));
    if (!beta) {
        exit(1);
    }
    *beta = 0.5f;

    i__ = 1;
    j = 1;
}

static void __attribute__((constructor)) initialize() {
    n = (integer *)malloc(sizeof(integer));
    if (!n) {
        exit(1);
    }
    init_vars();
}