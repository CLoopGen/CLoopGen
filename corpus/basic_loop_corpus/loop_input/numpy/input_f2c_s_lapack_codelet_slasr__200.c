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
integer i__;
integer j;
real temp;
real ctemp;
real stemp;

void init_vars() {
    // Allocate and initialize m and n
    m = (integer*)malloc(sizeof(integer));
    n = (integer*)malloc(sizeof(integer));
    
    *m = 1024;  // number of rows
    *n = 512;   // number of columns
    a_dim1 = *m; // leading dimension

    // Allocate arrays
    a = (real*)calloc((*m + 1) * (*n + 1), sizeof(real)); // 1-indexed, so we need up to m,n
    c__ = (real*)calloc(*m + 1, sizeof(real));
    s = (real*)calloc(*m + 1, sizeof(real));

    // Initialize rotation factors: make most non-trivial so the condition triggers
    for (int idx = 1; idx <= *m - 1; ++idx) {
        float angle = 0.1f * idx;
        c__[idx] = cosf(angle);
        s[idx] = sinf(angle);
    }

    // Initialize matrix a with non-zero values to propagate computation
    for (int i = 1; i <= *m; ++i) {
        for (int j = 1; j <= *n; ++j) {
            a[i + j * a_dim1] = (real)(i % 17 + j % 13);
        }
    }

    // Initialize scalars used in loop
    temp = 0.0f;
    ctemp = 0.0f;
    stemp = 0.0f;
    i__ = 0;
    i__1 = 0;
}