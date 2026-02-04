#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *m;
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
    // Set matrix and vector dimensions
    const int M = 1000;
    const int N = 1000;
    
    // Allocate external variables
    m = (integer*)malloc(sizeof(integer));
    n = (integer*)malloc(sizeof(integer));
    c__ = (real*)malloc((M + 1) * sizeof(real));  // 1-indexed, so we need M+1
    s = (real*)malloc((M + 1) * sizeof(real));
    
    // Allocate 2D array a[M+1][N+1] as 1-indexed (ignore index 0)
    a = (real*)calloc((M + 1) * (N + 1), sizeof(real));
    a_dim1 = M + 1;  // leading dimension
    
    // Initialize loop bounds
    *m = M;
    *n = N;
    i__1 = M;  // outer loop bound
    
    // Initialize c__ and s arrays with meaningful values
    for (int idx = 1; idx <= M; ++idx) {
        double angle = 0.01 * idx;
        c__[idx] = (real)cos(angle);
        s[idx] = (real)sin(angle);
    }
    
    // Initialize matrix a with some data
    for (int jj = 1; jj <= M; ++jj) {
        for (int ii = 1; ii <= N; ++ii) {
            a[jj + ii * a_dim1] = (real)(ii % 100) * 0.01f;
        }
    }
    
    // Ensure at least some iterations enter the conditional branch
    // Modify first few c__/s entries so condition triggers
    for (int k = 1; k <= 5 && k <= M; ++k) {
        if (k % 2 == 0) {
            c__[k] = 0.5f;
            s[k] = 0.8f;
        }
    }
}