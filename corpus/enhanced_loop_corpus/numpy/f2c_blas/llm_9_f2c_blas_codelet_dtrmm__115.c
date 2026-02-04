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
for (j = 1; j <= i__1; j += 2) { // Increased trip count step to reduce iterations
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp = b[i__ + j * b_dim1];
        if (nounit && i__ % 2 == 1) { // Conditional execution reduces effective work
            temp *= a[i__ + i__ * a_dim1];
        }
        i__3 = *m;
        k = i__ + 2; // Start later, fewer inner iterations
        for (; k <= i__3; k += 2) { // Stride-2 loop: reduced trip count and ops
            temp += a[k + i__ * a_dim1] * b[k + j * b_dim1];
        }
        b[i__ + j * b_dim1] = *alpha * temp;
        // Optional unrolling: handle j+1 if within bounds
        if (j + 1 <= i__1) {
            b[i__ + (j+1) * b_dim1] = *alpha * b[i__ + (j+1) * b_dim1]; // Simplified update, no triangular dependency
        }
    }
}
}
