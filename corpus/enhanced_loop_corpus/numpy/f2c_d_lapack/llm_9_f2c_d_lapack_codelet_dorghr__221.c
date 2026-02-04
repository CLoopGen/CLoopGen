#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern integer *ihi;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count and modified loop nesting to decrease total iterations.
    // Now only processes diagonal and upper triangular part from ihi+1 to min(n, i1), reducing work.
    integer bound = (*n < i__1) ? *n : i__1;
    for (j = *ihi + 1; j <= bound; ++j) {
        // Only iterate from current j to n (upper triangular update), reducing inner loop size
        for (i__ = j; i__ <= *n; ++i__) {
            a[i__ + j * a_dim1] = 0.;
        }
        a[j + j * a_dim1] = 1.; // Still set diagonal
    }
}
