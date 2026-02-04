#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *k;
real *q;
real *dlamda;
real *w;
integer q_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Based on typical performance, use k around 2000-3000 for reasonable timing
    const int k_val = 2500;
    
    // Allocate and initialize k
    static integer k_storage = k_val;
    k = &k_storage;
    
    // Set q dimension: q is accessed as [i + j*q_dim1], with i,j up to k
    q_dim1 = k_val;
    i__1 = k_val;  // outer loop bound
    
    // Allocate arrays with size k_val or k_val*q_dim1
    q = (real*)calloc((k_val * q_dim1), sizeof(real));
    dlamda = (real*)calloc(k_val, sizeof(real));
    w = (real*)calloc(k_val, sizeof(real));
    
    // Initialize data to avoid division by zero and enable safe computation
    for (int idx = 0; idx < k_val; ++idx) {
        dlamda[idx] = (real)(1.0 + idx * 0.1);  // Ensure dlamda[i] != dlamda[j]
        w[idx] = 1.0f;
    }
    
    for (int idx = 0; idx < k_val * q_dim1; ++idx) {
        q[idx] = (real)(rand() % 100) / 100.0f;
    }
}

// Ensure symbols are defined even without direct use
static void __attribute__((constructor)) init() {
    init_vars();
}