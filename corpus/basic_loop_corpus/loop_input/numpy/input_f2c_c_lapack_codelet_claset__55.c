#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *beta;
singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;

void init_vars() {
    // Allocate beta as a single complex number
    beta = (singlecomplex*)malloc(sizeof(singlecomplex));
    beta->r = 1.5f;
    beta->i = -0.8f;

    // Set matrix dimension and loop bound
    // We want total runtime ~0.01s; the loop runs i__1 iterations
    // Each iteration accesses one element in a 2D array stored as 1D
    // Assuming simple access, aim for enough data to take ~0.01s
    // Modern CPU can do billions of ops/sec, but cache/memory matters
    // Use ~16M elements to ensure non-trivial memory usage (~128 MB for floats)
    
    const size_t N = 4096;  // Choose N so that N*N*8 bytes ~ 128MB
    a_dim1 = N;
    i__1 = N;  // Loop from 1 to N

    // Allocate a as a square matrix: [1..N][1..N] -> index base 1
    // Total size: N*N elements, but we use 1-based indexing
    a = (singlecomplex*)calloc((N * N + 1), sizeof(singlecomplex));  // +1 for 1-based safety

    // Initialize some values in a if needed (not strictly necessary)
    // But ensure no out-of-bounds: indices go up to i__1 + i__1*a_dim1 = N + N*N
    // So max index is N*(N+1), which must be <= allocated size
    // Our allocation of N*N+1 may seem insufficient? Let's recompute:

    // Index used: i__ + i__ * a_dim1 = i__(1 + a_dim1) = i__*(1+N)
    // Max when i__=N -> N*(1+N) = N + N^2
    // So we need at least N^2 + N + 1 elements for 1-based indexing?
    // But original code likely assumes column-major with leading dimension

    // Actually, standard Fortran-style: a[i + j*a_dim1], indices start at 1
    // So valid i from 1 to a_dim1, j from 1 to ?
    // But here we only set diagonal: i__ + i__ * a_dim1 -> row i__, col i__
    // So we need space for at least a_dim1 x i__1 matrix -> N x N
    // And index = i__ + i__ * a_dim1 = i__(1 + a_dim1)
    // So maximum index is N*(1+N) = N + N^2

    free(a);
    const size_t total_size = N * N + N + 1;  // Safe upper bound
    a = (singlecomplex*)calloc(total_size, sizeof(singlecomplex));

    // Ensure beta is valid
    if (!beta) {
        beta = (singlecomplex*)malloc(sizeof(singlecomplex));
        beta->r = 1.0f;
        beta->i = 0.0f;
    }
}