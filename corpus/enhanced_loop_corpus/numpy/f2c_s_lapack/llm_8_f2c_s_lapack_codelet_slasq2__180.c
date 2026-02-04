#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern integer i__1;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    for (k = 2; k <= i__1 / 2; ++k) {
        z__[k] = z__[(k << 2) - 3] * 2.0f + 1.5f;
        z__[k + i__1 / 2] = z__[(k << 3) + 1] - 0.5f;
    }
}
