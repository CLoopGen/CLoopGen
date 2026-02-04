#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal psi;
extern doublereal dpsi;
extern doublereal temp;
extern doublereal erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 >= 1) {
        j = 1;
        temp = z__[j] / delta[j];
        psi += z__[j] * temp;
        dpsi += temp * temp;
        erretm += psi;
    }
    // Decreased depth: transformed into a single unrolled iteration (partial unrolling for depth reduction)
    // Assumes i__1 is at least 1, handles only first element explicitly without looping
    // Note: This variant loses generality but reflects a degenerate case of loop nesting (depth 0)
}
