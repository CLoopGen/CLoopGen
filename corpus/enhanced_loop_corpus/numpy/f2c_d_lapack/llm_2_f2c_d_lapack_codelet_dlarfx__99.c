#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern doublereal t1;
extern doublereal t2;
extern doublereal v1;
extern doublereal v2;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the layout assumption
    // Assume c__ is now accessed in a column-major consecutive pattern by unrolling two adjacent elements
    integer j1, j2;
    for (j = 1; j <= i__1; j += 2) {
        j1 = j;
        j2 = j + 1;

        if (j1 <= i__1) {
            sum = v1 * c__[j1 * c_dim1 + 1] + v2 * c__[j1 * c_dim1 + 2];
            c__[j1 * c_dim1 + 1] -= sum * t1;
            c__[j1 * c_dim1 + 2] -= sum * t2;
        }

        if (j2 <= i__1) {
            sum = v1 * c__[j2 * c_dim1 + 1] + v2 * c__[j2 * c_dim1 + 2];
            c__[j2 * c_dim1 + 1] -= sum * t1;
            c__[j2 * c_dim1 + 2] -= sum * t2;
        }
    }
}
