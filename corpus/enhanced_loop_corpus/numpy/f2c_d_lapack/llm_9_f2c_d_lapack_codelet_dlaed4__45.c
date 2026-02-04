#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal phi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with modified trip count and simplified arithmetic
    // Trip count halved by stepping more aggressively, and redundant division replaced with scaling
    doublereal inv_delta;
    for (j = *n; j >= i__1; j -= 2) {
        inv_delta = 1.0 / delta[j];
        phi += z__[j] * z__[j] * inv_delta * 0.5; // Less frequent and scaled contribution
    }
}
