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

extern integer *n;
extern doublecomplex *b;
extern doublereal *rwork;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern doublecomplex z__1;
extern integer jcol;
extern integer jrow;
extern integer jimag;
extern integer jreal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (jcol = 1; jcol <= i__1; ++jcol) {
    i__2 = *n;
    for (jrow = 1; jrow <= i__2; ++jrow) {
        // Change memory access to use a fixed stride pattern in rwork: accessing elements with a step of 2 (real, imag interleaved)
        integer idx_rwork = (jrow - 1) * 2 + (jcol - 1) * (*n) * 2; // Strided access across columns
        i__3 = jrow + jcol * b_dim1;
        z__1.r = rwork[idx_rwork] , z__1.i = rwork[idx_rwork + 1];
        b[i__3].r = z__1.r , b[i__3].i = z__1.i;
    }
}
}
