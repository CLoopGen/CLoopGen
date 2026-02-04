#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *n;
extern doublereal *a;
extern doublereal *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Transform matrix access from column-major (j + j*a_dim1) to row-major-like consecutive access
    // by precomputing base pointers and using incremental addressing for better spatial locality.
    integer jj = 1;
    for (j = 1; j <= i__1; ++j, jj += a_dim1) {
        temp = x[j];
        if (nounit) {
            temp *= a[jj + j - 1];  // a[j + j * a_dim1] accessed via precomputed offset
        }
        integer base_idx = jj + 1;  // base index for column j starting at row j+1
        i__2 = *n;
        for (i__ = j + 1; i__ <= i__2; ++i__, ++base_idx) {
            temp += a[base_idx] * x[i__];
        }
        x[j] = temp;
    }
}
