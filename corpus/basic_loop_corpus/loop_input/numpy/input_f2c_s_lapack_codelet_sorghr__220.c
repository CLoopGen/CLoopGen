#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *n;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

static real a_data[1 << 20]; // 4MB of data (about 2^20 floats)

void init_vars() {
    const int size = 1024; // n ≈ 1024 for ~0.01 sec runtime
    i__1 = size;
    n = (integer*)malloc(sizeof(integer));
    *n = size;
    a_dim1 = size + 10; // Ensure no out-of-bounds access
    a = a_data;

    // Ensure array bounds: a[i__ + j * a_dim1] with i__,j <= size
    // Maximum index: size + size * a_dim1 <= size*(a_dim1+1)
    // We allocated 1<<20 elements, so need: size*(a_dim1+1) <= 1<<20
    // With size=1024, a_dim1+1 <= 1024 -> a_dim1 <= 1023, but we set to 1034
    // So adjust size to fit
    if (size * (a_dim1 + 1) > (1 << 20)) {
        // Recompute safe size
        int max_size = (1 << 20) / (a_dim1 + 1);
        i__1 = max_size;
        *n = max_size;
    }
}