#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *m;
doublereal *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer kk;

static doublereal *a_data = NULL;

void init_vars() {
    // Problem parameters
    const integer n = 5000;          // columns (j dimension)
    const integer rows = 10000;      // total rows (i dimension)
    const integer leading_dim = rows + 100;  // leading dimension for a

    // Allocate 2D array 'a' as a contiguous block: rows x leading_dim
    a_data = (doublereal*)calloc(rows * leading_dim, sizeof(doublereal));
    if (!a_data) {
        exit(1);
    }

    a = a_data;
    a_dim1 = leading_dim;

    // Set m to point to the number of rows
    static integer m_val;
    m_val = rows;
    m = &m_val;

    // Loop bounds: j from 1 to i__1, where i__1 <= n
    i__1 = n;

    // Inner loop: i__ from kk+1 to *m
    kk = 0;  // so i__ starts at 1

    // Initialize loop counters
    i__ = 0;
    j = 0;
}

void cleanup() {
    free(a_data);
    a_data = NULL;
    a = NULL;
}