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
    // Variant 2: Introduce strided memory access via pointer arithmetic with precomputed base pointers
    // This variant replaces indexed array access with pointer arithmetic using strides,
    // simulating a transformed memory layout where we walk through memory with explicit stride control.
    
    for (k = 1; k <= i__1; ++k) {
        doublereal *a_col_k = &a[k * a_dim1];  // Base pointer for column k of A
        doublereal *b_col_k = &b[k * b_dim1];  // Base pointer for column k of B

        // First loop: update off-diagonal contributions
        i__2 = k - 1;
        for (j = 1; j <= i__2; ++j) {
            doublereal a_val = a_col_k[j];  // a[j + k*a_dim1]
            if (a_val != 0.) {
                temp = *alpha * a_val;
                doublereal *b_col_j = &b[j * b_dim1];  // Base pointer for column j of B
                i__3 = *m;
                // Use pointer increments instead of indexed access
                doublereal *bp_j = b_col_j + 1;  // Points to b[1 + j*b_dim1]
                doublereal *bp_k = b_col_k + 1;  // Points to b[1 + k*b_dim1]
                for (i__ = 1; i__ <= i__3; ++i__) {
                    *bp_j = *bp_j + temp * (*bp_k);  // b[i__ + j*b_dim1] += temp * b[i__ + k*b_dim1]
                    ++bp_j;
                    ++bp_k;
                }
            }
        }

        // Diagonal scaling
        temp = *alpha;
        if (nounit) {
            temp *= a_col_k[k];  // a[k + k*a_dim1]
        }
        if (temp != 1.) {
            i__2 = *m;
            doublereal *bp_k = b_col_k + 1;  // Start at b[1 + k*b_dim1]
            for (i__ = 1; i__ <= i__2; ++i__) {
                *bp_k = temp * (*bp_k);
                ++bp_k;
            }
        }
    }
}
