#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

typedef int integer;
typedef float real;
typedef int logical;

integer *m;
real *alpha;
real *a;
real *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer k;
logical nounit;

#define DATA_SIZE_M 2048

void init_vars() {
    // Allocate and initialize m
    m = (integer*)malloc(sizeof(integer));
    *m = DATA_SIZE_M;

    // Allocate and initialize alpha
    alpha = (real*)malloc(sizeof(real));
    *alpha = 1.5F;  // Not 1.F to trigger the scaling branch

    // Set matrix dimensions
    a_dim1 = DATA_SIZE_M;
    b_dim1 = DATA_SIZE_M;
    i__1 = DATA_SIZE_M;  // j loop bound

    // Allocate matrices a and b as 2D column-major arrays
    size_t a_size = (size_t)DATA_SIZE_M * DATA_SIZE_M;
    size_t b_size = (size_t)DATA_SIZE_M * DATA_SIZE_M;
    a = (real*)calloc(a_size, sizeof(real));
    b = (real*)calloc(b_size, sizeof(real));

    // Initialize diagonal of 'a' to non-zero values (simulate triangular matrix)
    for (int idx = 0; idx < DATA_SIZE_M; ++idx) {
        a[idx + idx * a_dim1] = 2.0F;
    }

    // Initialize b with non-zero values in first few columns to ensure activity
    for (int j = 1; j <= 1 && j <= DATA_SIZE_M; ++j) {
        for (int i = 1; i <= DATA_SIZE_M; ++i) {
            b[(i-1) + (j-1) * b_dim1] = (real)(i % 10 + j);
        }
    }

    // Ensure nounit is true (non-unit diagonal)
    nounit = 1;

    // Initialize loop temp variables to safe values
    i__2 = 0;
    i__3 = 0;
    i__ = 0;
    j = 0;
    k = 0;
}