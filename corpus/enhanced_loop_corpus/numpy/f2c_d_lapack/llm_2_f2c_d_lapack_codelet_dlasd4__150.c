#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal psi;
extern doublereal dpsi;
extern doublereal temp;
extern doublereal erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array base offset adjusted to zero-indexed,
    // and unrolling by a factor of 2 for improved spatial locality and reduced loop overhead.
    integer j;
    doublereal temp1, temp2;
    for (j = 1; j <= i__1 - 1; j += 2) {
        // First element in the unrolled pair
        temp1 = z__[j] / (work[j] * delta[j]);
        psi += z__[j] * temp1;
        dpsi += temp1 * temp1;
        erretm += psi;

        // Second element
        temp2 = z__[j+1] / (work[j+1] * delta[j+1]);
        psi += z__[j+1] * temp2;
        dpsi += temp2 * temp2;
        erretm += psi;
    }
    // Handle remaining element if i__1 is odd
    if (j <= i__1) {
        temp = z__[j] / (work[j] * delta[j]);
        psi += z__[j] * temp;
        dpsi += temp * temp;
        erretm += psi;
    }
}
