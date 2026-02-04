#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern integer *k;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *beta;
extern doublereal *c__;
extern integer a_dim1;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer l;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Modify memory access to use strided access with fixed stride over flattened index
// Introduce pointer arithmetic to simulate strided array traversal for improved vectorization potential
integer lda = a_dim1, ldc = c_dim1;
doublereal *aptr, *cptr;

for (j = 1; j <= i__1; ++j) {
    i__2 = *n;
    for (i__ = j; i__ <= i__2; ++i__) {
        temp = 0.;
        i__3 = *k;
        aptr = &a[i__ * lda + 1];      // Base pointer for column i, starting at row 1
        doublereal *bptr = &a[j * lda + 1];      // Base pointer for column j
        // Strided accumulation: step through elements with unit stride for cache efficiency
        for (l = 1; l <= i__3; ++l) {
            temp += aptr[l] * bptr[l];  // Unit-stride access instead of indirect indexing
        }
        cptr = &c__[i__ + j * ldc];
        if (*beta == 0.) {
            *cptr = *alpha * temp;
        } else {
            *cptr = *alpha * temp + *beta * (*cptr);
        }
    }
}
}
