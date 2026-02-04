#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *x;
extern integer *incx;
extern doublereal *y;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer jx;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base pointer for column j of matrix 'a'
    for (j = 1; j <= i__1; ++j) {
        if (x[jx] != 0.) {
            temp = *alpha * x[jx];
            doublereal *a_col_j = &a[j * a_dim1]; // Base address of column j
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                y[i__] += temp * a_col_j[i__]; // Consecutive access in column j
            }
        }
        jx += *incx;
    }
}
