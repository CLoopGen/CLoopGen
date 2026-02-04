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
extern integer i__;
extern integer j;
extern integer k;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Indirect memory access via pointer arithmetic to simulate indirect indexing
doublereal *base_a = a - 1;  // Adjust base for 1-based indexing simulation
doublereal *base_b = b - 1;
integer lda = a_dim1;
integer ldb = b_dim1;

for (j = *n; j >= 1; --j) {
    temp = *alpha;
    if (nounit) {
        temp *= *(base_a + j + j * lda);  // Strided access using pointer
    }
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
        *(base_b + i__ + j * ldb) = temp * *(base_b + i__ + j * ldb);
    }
    i__1 = j - 1;
    for (k = 1; k <= i__1; ++k) {
        doublereal a_val = *(base_a + k + j * lda);
        if (a_val != 0.) {
            temp = *alpha * a_val;
            i__2 = *m;
            // Use temporary pointers for consecutive access in b columns
            doublereal *bp_j = base_b + j * ldb;
            doublereal *bp_k = base_b + k * ldb;
            for (i__ = 1; i__ <= i__2; ++i__) {
                *(bp_j + i__) += temp * *(bp_k + i__);  // Sequential access: improves cache locality
            }
        }
    }
}
}
