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
    // Set problem size for ~0.01 sec runtime on modern CPU
    const int M = 4096;        // *m value
    const int N = 512;         // related to i__1 (j-loop bound)
    
    // Allocate arrays
    m = (integer*)malloc(sizeof(integer));
    c__ = (real*)calloc(N + 2, sizeof(real));
    s = (real*)calloc(N + 2, sizeof(real));
    a = (singlecomplex*)calloc(M * (N + 2), sizeof(singlecomplex));
    
    // Initialize control parameters
    *m = M;
    a_dim1 = M;  // leading dimension of matrix 'a'
    i__1 = N;    // upper bound for j loop: j <= i__1

    // Initialize c__ and s arrays so that some iterations enter the if-body
    for (int j = 1; j <= N; ++j) {
        c__[j] = (j % 3 == 0) ? 0.8f : 1.0f;  // make some != 1.F
        s[j]   = (j % 3 == 0) ? 0.6f : 0.0f;  // make some != 0.F
    }

    // Initialize matrix a with sample data within safe bounds
    for (int col = 1; col <= N + 1; ++col) {
        for (int row = 1; row <= M; ++row) {
            int idx = row + col * a_dim1;
            if (idx < M * (N + 2)) {
                a[idx].r = (real)(row % 7) / 7.0f;
                a[idx].i = (real)(col % 5) / 5.0f;
            }
        }
    }

    // Initialize temporaries to zero
    temp.r = 0.0f; temp.i = 0.0f;
    ctemp = 0.0f;
    stemp = 0.0f;
}