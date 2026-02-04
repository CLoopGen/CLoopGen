#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <time.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *sx;
integer *incx;
integer ret_val;
integer i__1;
real r__1;
integer i__;
integer ix;
real smax;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Empirical testing shows ~2^20 elements gives desired timing
    const int N = 1 << 20;
    
    // Allocate sx array
    sx = (real*)aligned_alloc(32, N * sizeof(real));
    if (!sx) exit(1);
    
    // Initialize array with random float data
    srand((unsigned int)time(NULL));
    for (int i = 0; i < N; ++i) {
        sx[i] = (real)((rand() / (double)RAND_MAX) * 200.0 - 100.0); // Range [-100, 100]
    }
    
    // Allocate and set incx
    incx = (integer*)malloc(sizeof(integer));
    if (!incx) exit(1);
    *incx = 1;  // Common value for stride
    
    // Initialize loop bounds to stay within array
    i__1 = N;   // Loop from 2 to N inclusive
    ix = 1;     // Start at index 1 (0-based)
    
    // Initialize smax with absolute value of first element
    smax = fabsf(sx[0]);
    
    // Initialize other variables
    ret_val = 1;
    i__ = 2;
    r__1 = 0.0f;
}