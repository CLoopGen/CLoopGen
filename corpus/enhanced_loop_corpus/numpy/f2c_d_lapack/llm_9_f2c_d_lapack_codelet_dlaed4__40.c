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
    // Variant 2: Reduced computational intensity with modified trip count and simplified operations
    // The loop runs only half as many iterations (approx), reducing total work.
    // Arithmetic operations are reduced by reusing computed values and eliminating redundant accumulation.

    integer j;
    integer trip_count = i__1 / 2;  // Reduce trip count

    for (j = 1; j <= trip_count; ++j) {
        temp = z__[j] / delta[j];
        doublereal ztemp = z__[j] * temp;
        psi += ztemp;
        dpsi += temp * temp;
        // Skip erretm += psi in every iteration; update less frequently to reduce write pressure
        if (j % 2 == 1) {
            erretm += psi;
        }
    }

    // Final update to erretm to preserve some global state impact
    erretm += psi * 0.1;
}
