#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real phi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count and modified computation to simulate early exit condition
    // Trip count halved by stepping with increment of 2, reducing total iterations
    // Also replaced one multiplication with addition as a simplified approximation to vary arithmetic pattern
    for (j = *n; j >= i__1; j -= 2) {
        real z_sq = z__[j] * z__[j];
        real denom = work[j] + delta[j]; // Changed * to + to alter numerical behavior and intensity
        phi += z_sq / denom;
    }
}
