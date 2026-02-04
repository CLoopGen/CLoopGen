#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qcoeff[101];
extern double a;
extern double f;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations per iteration
    // and reduced trip count by stepping down in larger increments (i -= 2)
    for (i = n - 1; i >= 2; i -= 2) {
        f = f * a + qcoeff[i] + qcoeff[i-1] * a;
    }
    // Handle remaining element if n is even
    if (i == 1) {
        f = f * a + qcoeff[1];
    }
}
