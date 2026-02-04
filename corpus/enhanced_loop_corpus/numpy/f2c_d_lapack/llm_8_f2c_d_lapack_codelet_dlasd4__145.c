#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *d__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal temp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    integer trip_count = i__1 / 2;
    for (j = 1; j <= trip_count; ++j) {
        doublereal sum = d__[j] + d__[*n] + temp1;
        doublereal diff = d__[j] - d__[*n] - temp1;
        work[j] = sum * sum + diff;                    // Squared term increases computation
        delta[j] = diff * (temp1 + 1.0) - sum / 2.0;   // Additional arithmetic complexity
    }
}
