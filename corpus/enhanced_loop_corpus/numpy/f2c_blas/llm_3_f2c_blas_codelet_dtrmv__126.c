#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *n;
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
    // Variant 2: Strided Memory Access Pattern
    // Introduce a fixed stride in the inner loop to simulate access with gaps,
    // mimicking scenarios like strided data layouts or padding in matrices.
    const integer stride = a_dim1;  // Original stride preserved
    for (j = 1; j <= i__1; ++j) {
        temp = x[j];
        if (nounit) {
            temp *= a[j + j * stride];
        }
        i__2 = *n;
        integer idx = (j + 1) + j * stride;  // Initial index into column j, row j+1
        for (i__ = j + 1; i__ <= i__2; ++i__, idx += stride) {
            temp += a[idx] * x[i__];
        }
        x[j] = temp;
    }
}
