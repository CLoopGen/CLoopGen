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
extern doublereal *b;
extern doublereal *beta;
extern doublereal *c__;
extern integer a_dim1;
extern integer b_dim1;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer l;
extern doublereal temp1;
extern doublereal temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Modify memory access pattern to use indirect indexing via pointer arithmetic
// Simulate indirect access using base pointers and precomputed offsets
doublereal *a_base = &a[a_dim1];
doublereal *b_base = &b[b_dim1];
doublereal *c_base = &c__[c_dim1];

for (j = 1; j <= i__1; ++j) {
    i__2 = *n;
    for (i__ = j; i__ <= i__2; ++i__) {
        temp1 = 0.;
        temp2 = 0.;
        i__3 = *k;

        // Use indirect access: compute row/column offsets once
        doublereal *a_i = &a[i__ * a_dim1];
        doublereal *b_i = &b[i__ * b_dim1];
        doublereal *a_j = &a[j * a_dim1];
        doublereal *b_j = &b[j * b_dim1];

        for (l = 1; l <= i__3; ++l) {
            // Access elements using precomputed row bases (more cache-friendly)
            temp1 += a_i[l] * b_j[l];
            temp2 += b_i[l] * a_j[l];
        }
        if (*beta == 0.) {
            c_base[i__ * c_dim1 + j] = *alpha * temp1 + *alpha * temp2;
        } else {
            c_base[i__ * c_dim1 + j] = *beta * c_base[i__ * c_dim1 + j] + *alpha * temp1 + *alpha * temp2;
        }
    }
}
}
