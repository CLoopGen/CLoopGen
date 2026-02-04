#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern doublereal d__1;
extern integer i__;
extern integer j;
extern doublereal sum;
extern doublereal value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the iteration order
    // We now iterate over rows first (i__) and then columns (j), accessing a in row-major fashion
    // This improves spatial locality if the matrix is stored in row-major layout
    for (i__ = 1; i__ <= *m; ++i__) {
        i__2 = i__1;
        for (j = 1; j <= i__2; ++j) {
            sum = (d__1 = a[i__ + j * a_dim1], ((d__1) >= 0 ? (d__1) : -(d__1)));
            value = ((value) >= (sum) ? (value) : (sum));
        }
    }
}
