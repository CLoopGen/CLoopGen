#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *n;
real *c__;
real *s;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
real temp;
real ctemp;
real stemp;

void init_vars() {
    // Set problem size
    const int N = 4096;  // Adjusted to ensure ~0.01s runtime and safe memory access

    // Allocate arrays
    n = (integer*)malloc(sizeof(integer));
    c__ = (real*)malloc((N + 1) * sizeof(real));
    s = (real*)malloc((N + 1) * sizeof(real));
    a = (real*)malloc((N + 1) * (N + 1) * sizeof(real));

    // Initialize parameters
    *n = N;
    a_dim1 = N + 1;  // leading dimension of matrix 'a'
    i__1 = N - 1;    // ensures j+1 <= N, so no out-of-bounds access

    // Initialize c__ and s arrays: mostly identity case (ctemp=1, stemp=0), but some nontrivial
    for (int j = 1; j <= i__1; ++j) {
        if (j % 10 == 0) {
            c__[j] = 0.8F;
            s[j] = 0.6F;
        } else {
            c__[j] = 1.0F;
            s[j] = 0.0F;
        }
    }

    // Initialize matrix 'a' with non-zero values
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            a[j + i * a_dim1] = (real)(i + j);
        }
    }

    // Initialize loop indices and temps
    i__ = 0;
    j = 0;
    temp = 0.0F;
    ctemp = 0.0F;
    stemp = 0.0F;
}