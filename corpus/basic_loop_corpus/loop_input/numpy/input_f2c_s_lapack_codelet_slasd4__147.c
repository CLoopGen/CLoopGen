#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;

integer i__1 = 0;
integer *i__ = NULL;
real *d__ = NULL;
real *delta = NULL;
real *work = NULL;
integer j = 0;
real eta = 0.0f;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t element_size = sizeof(real);
    const size_t array_elements = (data_size_mb * 1024 * 1024) / element_size;
    
    i__1 = (integer)array_elements;
    
    i__ = (integer*)malloc(sizeof(integer));
    *i__ = 1;
    
    d__ = (real*)aligned_alloc(32, sizeof(real) * (i__1 + 1));
    delta = (real*)aligned_alloc(32, sizeof(real) * (i__1 + 1));
    work = (real*)aligned_alloc(32, sizeof(real) * (i__1 + 1));
    
    eta = 1.5f;
    
    for (integer idx = 1; idx <= i__1; ++idx) {
        d__[idx] = (real)(idx * 0.1);
    }
    
    for (integer idx = 1; idx <= i__1; ++idx) {
        delta[idx] = 0.0f;
        work[idx] = 0.0f;
    }
}