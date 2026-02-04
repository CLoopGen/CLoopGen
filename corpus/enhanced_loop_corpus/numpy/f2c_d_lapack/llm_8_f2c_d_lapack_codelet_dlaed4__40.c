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
    // Variant 1: Increased computational intensity with additional arithmetic operations and doubled effective trip count
    // The loop body now includes extra floating-point operations to increase computation per iteration.
    // We also unroll the loop by a factor of 2 to reduce loop overhead and increase instruction-level parallelism.

    integer j;
    for (j = 1; j <= i__1 - 1; j += 2) {
        // First iteration of unrolled loop
        doublereal temp1 = z__[j] / delta[j];
        psi += z__[j] * temp1;
        dpsi += temp1 * temp1;
        erretm += psi;

        // Second iteration of unrolled loop
        doublereal temp2 = z__[j+1] / delta[j+1];
        psi += z__[j+1] * temp2;
        dpsi += temp2 * temp2;
        erretm += psi;

        // Additional computational load: simulate a light dependency chain
        erretm += temp1 * temp2 + (z__[j] + z__[j+1]) * 0.5;
    }

    // Handle odd-sized i__1
    if (j <= i__1) {
        temp = z__[j] / delta[j];
        psi += z__[j] * temp;
        dpsi += temp * temp;
        erretm += psi;
    }
}
