#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *m;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer k;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorder loops to access memory in a more contiguous manner by swapping j and i loops
    // and precomputing base indices to enhance spatial locality for array 'b' and 'a'
    integer jj, ii, kk;
    doublereal *b_col, *a_col;
    
    for (jj = 1; jj <= i__1; ++jj) {
        b_col = &b[jj * b_dim1];  // Base pointer to column jj of b
        temp = 0.0;
        i__2 = *m;
        for (ii = 1; ii <= i__2; ++ii) {
            temp = b_col[ii];
            if (nounit) {
                temp *= a[ii + ii * a_dim1];
            }
            a_col = &a[ii * a_dim1];  // Base pointer to column ii of a
            i__3 = *m;
            for (kk = ii + 1; kk <= i__3; ++kk) {
                temp += a_col[kk] * b_col[kk];
            }
            b_col[ii] = *alpha * temp;
        }
    }
}
