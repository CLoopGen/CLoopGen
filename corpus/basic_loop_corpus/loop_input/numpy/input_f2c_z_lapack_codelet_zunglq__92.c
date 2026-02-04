#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *m;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer kk;

void init_vars() {
    // Set problem size to ensure ~0.01s runtime
    // The loop iterates over j in [1, i__1] and i__ in [kk+1, m]
    // Total iterations: i__1 * (*m - kk)
    // We aim for roughly 10-50 million operations for ~0.01s on modern CPU

    i__1 = 2000;           // j from 1 to 2000
    kk = 1000;
    m = (integer*)malloc(sizeof(integer));
    *m = 3000;              // i__ from 1001 to 3000 -> 2000 iterations per j
    a_dim1 = 4000;          // leading dimension for 2D indexing

    // Total memory needed: at least (3000 + 1) * 4000 elements to be safe
    size_t total_elements = (size_t)(*m + 1) * (size_t)(a_dim1 + 1);
    a = (doublecomplex*)calloc(total_elements, sizeof(doublecomplex));
    if (!a || !m) {
        exit(1);
    }

    // Ensure all variables used in indexing are initialized
    i__2 = *m;
    i__3 = 0;
    i__ = 0;
    j = 0;
}