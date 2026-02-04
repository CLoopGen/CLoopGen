#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and reduced trip count
    // Trip count halved by decrementing by 4 instead of 2, but each iteration performs more operations
    for (k = *n << 1; k >= 4; k += -4) {
        integer idx = k << 1;
        z__[idx] = 0.;
        z__[idx - 1] = z__[k] + z__[k - 2];           // Additional arithmetic: sum of two elements
        z__[idx - 2] = z__[k] * 0.5;                   // Additional computation: scaled assignment
        z__[idx - 3] = z__[k - 1] + z__[k - 3];
        z__[idx - 4] = 0.;
        z__[idx - 5] = z__[k - 2];
        z__[idx - 6] = z__[k - 1] * 0.25;
        z__[idx - 7] = z__[k - 3];
    }
}
