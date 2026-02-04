#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef float real;
typedef int integer;

real *d__;
real *z__;
real *dsigma;
real *u2;
integer *idxc;
integer *idxq;
integer *coltyp;
integer u2_dim1;
integer i__1;
integer i__;

void init_vars() {
    const size_t N = 64 << 10;  // 64K elements (~1MB for float, ~256KB for int)
    
    i__1 = N - 1;

    d__ = (real*)calloc(N, sizeof(real));
    z__ = (real*)calloc(N, sizeof(real));
    dsigma = (real*)calloc(N, sizeof(real));
    u2 = (real*)calloc(N * 2, sizeof(real));  // 2D-like access with u2_dim1
    idxc = (integer*)calloc(N, sizeof(integer));
    idxq = (integer*)calloc(N, sizeof(integer));
    coltyp = (integer*)calloc(N, sizeof(integer));

    u2_dim1 = N;

    for (size_t i = 0; i < N; ++i) {
        d__[i] = (real)(1.0 + i * 0.001);
        z__[i] = (real)(2.0 + i * 0.002);
        coltyp[i] = (i % 3) + 1;
        idxq[i] = (i < (size_t)i__1) ? (i + 1) : 0;  // idxq[i__] used as index, ensure valid
    }

    idxq[0] = 0;
    for (size_t i = 1; i < N; ++i) {
        idxq[i] = (i <= (size_t)i__1) ? rand() % (N-1) + 1 : 0;
    }
}