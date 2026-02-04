#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;
typedef int logical;

integer *n;
real *a;
real *x;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
real temp;
logical nounit;

#define DATA_SIZE_MB 64
#define TOTAL_SIZE (DATA_SIZE_MB * 1024 * 1024)
#define MATRIX_ELEM_COUNT (TOTAL_SIZE / sizeof(real))
#define VECTOR_SIZE sqrt(MATRIX_ELEM_COUNT)

void init_vars() {
    const size_t vec_size = (size_t)ceil(sqrt(MATRIX_ELEM_COUNT));
    
    n = (integer*)malloc(sizeof(integer));
    x = (real*)malloc(vec_size * sizeof(real));
    a = (real*)malloc(vec_size * vec_size * sizeof(real));
    
    *n = vec_size;
    a_dim1 = vec_size;
    i__1 = vec_size - 1;
    nounit = 1;

    for (size_t idx = 0; idx < vec_size; ++idx) {
        x[idx] = 1.0f + (real)(idx % 10);
        for (size_t jdx = 0; jdx < vec_size; ++jdx) {
            a[idx + jdx * a_dim1] = (real)(1 + abs((long)(idx - jdx)) % 7) * 0.1f;
        }
    }

    i__ = 0;
    j = 0;
    temp = 0.0f;
    i__2 = 0;
}