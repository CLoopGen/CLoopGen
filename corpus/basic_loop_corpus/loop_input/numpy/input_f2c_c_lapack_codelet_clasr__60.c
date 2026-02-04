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

integer *n;
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
    // Allocate and initialize scalar variables
    n = (integer*)malloc(sizeof(integer));
    *n = 1000;

    a_dim1 = *n;
    i__1 = *n - 1;

    // Allocate arrays with appropriate sizes
    c__ = (real*)calloc(*n + 1, sizeof(real));
    s = (real*)calloc(*n + 1, sizeof(real));
    
    // Allocate matrix 'a' as 2D array indexed as [j + i*a_dim1], so we need at least (*n+1) rows and (i__1+1) columns?
    // To be safe, allocate a square matrix of size (*n+1) x (*n+1)
    a = (singlecomplex*)calloc((*n + 1) * (*n + 1), sizeof(singlecomplex));

    // Initialize c__ and s for meaningful computation
    for (int idx = 1; idx <= i__1; ++idx) {
        c__[idx] = 0.8f;  // not 1.0 to ensure the condition triggers
        s[idx] = 0.6f;   // not 0.0
    }

    // Initialize matrix a with some values to avoid zero-only data
    for (int i = 1; i <= *n; ++i) {
        for (int j = 1; j <= *n; ++j) {
            int idx = j + i * a_dim1;
            a[idx].r = (real)(i % 100) / 100.0f;
            a[idx].i = (real)(j % 100) / 100.0f;
        }
    }

    // Initialize temporaries to zero
    temp.r = 0.0f; temp.i = 0.0f;
    ctemp = 0.0f;
    stemp = 0.0f;
    q__1.r = 0.0f; q__1.i = 0.0f;
    q__2.r = 0.0f; q__2.i = 0.0f;
    q__3.r = 0.0f; q__3.i = 0.0f;
    i__ = 0;
    j = 0;
}