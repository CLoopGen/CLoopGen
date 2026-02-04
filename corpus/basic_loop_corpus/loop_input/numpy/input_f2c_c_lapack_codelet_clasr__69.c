#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
singlecomplex q__1;
singlecomplex q__2;
singlecomplex q__3;
integer i__;
integer j;
singlecomplex temp;
real ctemp;
real stemp;

void init_vars() {
    // Allocate and initialize scalar pointers
    m = (integer*)malloc(sizeof(integer));
    n = (integer*)malloc(sizeof(integer));
    c__ = (real*)malloc(1024 * sizeof(real));
    s = (real*)malloc(1024 * sizeof(real));

    // Set matrix dimensions
    *m = 512;  // number of rows
    *n = 512;  // number of columns (j goes from n down to 2)

    a_dim1 = *m;  // leading dimension of matrix a

    // Allocate matrix a with size m x n
    a = (singlecomplex*)calloc((*m) * (*n), sizeof(singlecomplex));

    // Initialize c__ and s arrays with meaningful values
    for (int idx = 0; idx < 1024; ++idx) {
        if (idx < *n) {
            c__[idx] = 0.8f;  // typical cosine value
            s[idx] = 0.6f;    // typical sine value
        } else {
            c__[idx] = 1.0f;
            s[idx] = 0.0f;
        }
    }

    // Initialize matrix a with sample data to avoid zero optimizations
    for (int i = 0; i < *m; ++i) {
        for (int j = 0; j < *n; ++j) {
            int idx = i + j * a_dim1;
            a[idx].r = (real)(i % 7 + 1);
            a[idx].i = (real)(j % 11 + 1);
        }
    }

    // Ensure that accesses in the loop: i__ + j * a_dim1 are within bounds
    // Maximum index: i = *m, j = *n -> index = *m + *n * a_dim1 = *m + *n * *m
    // Our allocation: (*m) * (*n) covers all column-major indices up to (*n-1)*a_dim1 + (*m-1)
    // So max linear index is (*n-1)*a_dim1 + (*m-1) = (*n-1)*(*m) + (*m-1) = *n*(*m) - 1
    // The loop uses i__ + j * a_dim1 where i__ <= *m and j <= *n
    // When i__ = *m and j = *n, index = *m + *n * *m -> this exceeds by *m
    // Therefore, we must ensure j only goes up to *n, but our array has columns 0..*n-1
    // So we adjust: use j from *n down to 2, so valid column indices are j=2..*n
    // But our matrix has columns 0 to *n-1 -> so we need to make sure j <= *n-1
    // Hence set *n = min(requested, actual_columns) -> already allocated *n columns

    // Correction: since j starts at *n and accesses column j, and our columns are 0-indexed,
    // we must have *n <= allocated_columns. We allocated *n columns (0..*n-1), so j must be <= *n-1.
    // Therefore, we reduce *n by 1 to make j = *n access the last valid column.
    // But wait: loop is: for (j = *n; j >= 2; --j)
    // If *n = 512, then j goes from 512 down to 2 -> we need column indices 2 to 512
    // But our matrix has columns 0 to 511 -> column 512 does not exist.

    // Fix: reassign *n to be one less than the number of columns
    // Let's instead allocate one extra row and column implicitly via padding?
    // Better: change *n to 511 so j goes from 511 to 2 -> columns 2 to 511, which are valid in 0..511

    *n = 511;
    // And update c__ and s to have valid entries for index j-1 = 510
    // Already done above (initialized up to 1024)

    // Also ensure m is consistent
    *m = 512;

    // Reset a_dim1 accordingly
    a_dim1 = 512;

    // Reallocate a to cover [1..m][1..n] if using 1-based indexing?
    // Code uses: i__ + j * a_dim1 -> likely 1-based indexing (FORTRAN-style)
    // In FORTRAN, A(i,j) = base + (i-1) + (j-1)*lda
    // But here: i__ + j * a_dim1 -> implies 1-based: A(i,j) = a[i + j*a_dim1]
    // So we need matrix indexed from 1..m, 1..n
    // Therefore, allocate (m+1) * (n+1) to allow 1-based indexing
    free(a);
    a = (singlecomplex*)calloc(((*m)+1) * ((*n)+1), sizeof(singlecomplex));
    a_dim1 = (*m)+1;

    // Re-initialize matrix a for 1-based indexing: fill indices i=1..m, j=1..n
    for (int i = 1; i <= *m; ++i) {
        for (int j = 1; j <= *n; ++j) {
            int idx = i + j * a_dim1;
            a[idx].r = (real)((i % 7) + 1);
            a[idx].i = (real)((j % 11) + 1);
        }
    }

    // Initialize c__ and s for indices 1 to *n (used as j-1 from 1 to *n-1)
    for (int j = 1; j < 1024; ++j) {
        if (j <= *n) {
            c__[j-1] = (j % 3 == 0) ? 1.0f : 0.8f;
            s[j-1]   = (j % 3 == 0) ? 0.0f : 0.6f;
        } else {
            c__[j-1] = 1.0f;
            s[j-1] = 0.0f;
        }
    }
}