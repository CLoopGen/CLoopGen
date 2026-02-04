#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *m;
extern integer *n;
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
    // Variant 1: Change memory access pattern to use row-major consecutive access by transposing the effective indexing
    // We simulate a transpose-like access for 'a' and 'b' by flipping index arithmetic (conceptually treating matrices as transposed)
    // This changes spatial locality and access stride for cache performance

    for (j = 1; j <= i__1; ++j) {
        temp = *alpha;
        if (nounit) {
            temp *= a[j * a_dim1 + j];  // same element, but emphasize linear offset
        }
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            b[i__ * b_dim1 + j] = temp * b[i__ * b_dim1 + j];  // now using row-major layout assumption
        }
        i__2 = *n;
        for (k = j + 1; k <= i__2; ++k) {
            if (a[j * a_dim1 + k] != 0.) {  // swapped indices: accessing transposed 'a'
                temp = *alpha * a[j * a_dim1 + k];
                i__3 = *m;
                for (i__ = 1; i__ <= i__3; ++i__) {
                    b[i__ * b_dim1 + j] += temp * b[i__ * b_dim1 + k];  // row-major update
                }
            }
        }
    }
}
