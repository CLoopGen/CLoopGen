#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *m;
extern integer *n;
extern real *alpha;
extern real *a;
extern real *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer k;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Modify memory access pattern to use strided access for array 'b'
    // Instead of accessing b[i__ + k * b_dim1] in inner loops, we precompute base pointers with stride = b_dim1
    // This changes the access pattern to stride-based by iterating through rows with fixed column offsets.

    for (k = *n; k >= 1; --k) {
        real *b_k_col = &b[k * b_dim1];  // Base pointer for column k of b (strided access base)

        if (nounit) {
            temp = 1.F / a[k + k * a_dim1];
            i__1 = *m;
            for (i__ = 1; i__ <= i__1; ++i__) {
                b_k_col[i__] = temp * b_k_col[i__];  // Strided write via precomputed column base
            }
        }

        i__1 = k - 1;
        for (j = 1; j <= i__1; ++j) {
            if (a[j + k * a_dim1] != 0.F) {
                temp = a[j + k * a_dim1];
                real *b_j_col = &b[j * b_dim1];      // Base pointer for column j
                i__2 = *m;
                for (i__ = 1; i__ <= i__2; ++i__) {
                    b_j_col[i__] -= temp * b_k_col[i__];  // Strided read/write using column bases
                }
            }
        }

        if (*alpha != 1.F) {
            i__1 = *m;
            for (i__ = 1; i__ <= i__1; ++i__) {
                b_k_col[i__] = *alpha * b_k_col[i__];  // Final scaling using same strided access
            }
        }
    }
}
