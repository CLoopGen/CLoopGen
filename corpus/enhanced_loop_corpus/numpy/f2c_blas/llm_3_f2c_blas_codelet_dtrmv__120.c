#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

typedef int logical;

extern doublereal *a;
extern doublereal *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    for (int jj = 0; jj < 2 && (jj + j) <= i__1; ++jj) {
        integer current_j = j + jj;
        if (x[current_j] != 0.) {
            temp = x[current_j];
            i__2 = current_j - 1;
            for (i__ = 1; i__ <= i__2; ++i__) {
                x[i__] += temp * a[i__ + current_j * a_dim1];
            }
            if (nounit) {
                x[current_j] *= a[current_j + current_j * a_dim1];
            }
        }
    }
}
}
