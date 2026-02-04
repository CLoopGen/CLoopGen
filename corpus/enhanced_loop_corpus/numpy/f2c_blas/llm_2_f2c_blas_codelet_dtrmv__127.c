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
extern integer *incx;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jx;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Modify access to x[] to be consecutive by precomputing indices into a local array
    // This reduces strided access when incx != 1, improving cache performance
    
    integer base_ix = jx;
    for (j = 1; j <= i__1; ++j) {
        temp = x[base_ix];
        if (nounit) {
            temp *= a[j + j * a_dim1];
        }
        i__2 = *n;
        for (i__ = j + 1; i__ <= i__2; ++i__) {
            base_ix += *incx;
            temp += a[i__ + j * a_dim1] * x[base_ix];
        }
        x[jx] = temp;
        jx += *incx;
        base_ix = jx; // Reset base index for next iteration
    }
}
