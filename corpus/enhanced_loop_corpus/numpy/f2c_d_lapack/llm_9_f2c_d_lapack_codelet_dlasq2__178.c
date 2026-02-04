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
    // Variant 2: Reduced computational intensity with increased trip count and simplified operations
    // Loop runs twice as many times (step of -1 instead of -2), but each iteration does less work
    for (k = *n << 1; k >= 1; k--) {
        if (k & 1) {
            // Odd index: only assign one value
            z__[(k << 1) - 1] = z__[k];
        } else {
            // Even index: update every other element with minimal ops
            z__[k * 2] = 0.;
            z__[(k << 1) - 2] = 0.;
        }
    }
}
