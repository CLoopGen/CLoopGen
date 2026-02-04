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
integer *n;
doublereal *c__;
doublereal *s;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
doublecomplex z__1;
doublecomplex z__2;
doublecomplex z__3;
integer i__;
integer j;
doublecomplex temp;
doublereal ctemp;
doublereal stemp;

void init_vars() {
    // Set problem dimensions
    const int M = 4096;  // rows
    const int N = 512;   // columns

    // Allocate memory
    m = (integer*)malloc(sizeof(integer));
    n = (integer*)malloc(sizeof(integer));
    c__ = (doublereal*)calloc(N + 1, sizeof(doublereal));  // 1-indexed: index 1..N
    s = (doublereal*)calloc(N + 1, sizeof(doublereal));
    a = (doublecomplex*)calloc((M + 1) * (N + 1), sizeof(doublecomplex));  // 1-indexed: [1..M][1..N]

    // Initialize parameters
    *m = M;
    *n = N;
    a_dim1 = M + 1;  // leading dimension for matrix a (row stride)
    i__1 = N;        // outer loop bound: j <= i__1

    // Initialize c and s arrays
    for (int j = 1; j <= N; ++j) {
        c__[j] = 0.8;  // typical rotation cosine
        s[j] = 0.6;   // typical rotation sine
    }

    // Initialize matrix a with sample data
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            int idx = i + j * a_dim1;
            a[idx].r = (doublereal)(i % 100) / 100.0;
            a[idx].i = (doublereal)(j % 100) / 100.0;
        }
    }

    // Ensure the last column used (*n) is safe to access
    for (int i = 1; i <= M; ++i) {
        int idx = i + N * a_dim1;
        if (idx >= (M + 1)*(N + 1)) {
            fprintf(stderr, "Index out of bounds\n");
            exit(1);
        }
    }
}