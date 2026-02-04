#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
integer *n;
real *c__;
real *s;
singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
singlecomplex q__1;
singlecomplex q__2;
singlecomplex q__3;
integer i__;
integer j;
singlecomplex temp;
real ctemp;
real stemp;

void init_vars() {
    const size_t approx_data_size = 64 * 1024 * 1024; // ~64 MB of data for singlecomplex array
    const size_t bytes_per_element = sizeof(singlecomplex);
    const integer approx_elements = (integer)(approx_data_size / bytes_per_element);
    const integer sqrt_approx = (integer)sqrt((double)approx_elements);

    // Set dimensions to ensure memory safety and reasonable computation load
    integer M = sqrt_approx;
    integer N = sqrt_approx;

    // Allocate and initialize scalar pointers
    m = (integer*)malloc(sizeof(integer));
    n = (integer*)malloc(sizeof(integer));
    *m = M;
    *n = N;

    // Allocate arrays
    c__ = (real*)calloc(N + 1, sizeof(real)); // 1-based indexing: index from 1 to N
    s = (real*)calloc(N + 1, sizeof(real));
    a = (singlecomplex*)calloc((M * N) + (N + 1), sizeof(singlecomplex)); // conservative allocation

    // Initialize rotation factors and matrix
    for (integer idx = 1; idx <= N; ++idx) {
        c__[idx] = 0.8f; // some value not equal to 1.0
        s[idx] = 0.6f;  // some non-zero value
    }

    for (integer i = 1; i <= M; ++i) {
        for (integer j = 1; j <= N; ++j) {
            integer idx = j + i * N; // assuming column-major layout with leading dimension N
            if (idx < (M * N) + (N + 1)) {
                a[idx].r = (real)(i * 0.1f);
                a[idx].i = (real)(j * 0.1f);
            }
        }
    }

    a_dim1 = N; // leading dimension
    i__1 = N;   // outer loop bound
}