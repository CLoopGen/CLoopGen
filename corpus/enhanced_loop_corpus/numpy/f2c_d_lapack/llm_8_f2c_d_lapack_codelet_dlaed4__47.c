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
extern doublereal dphi;
extern doublereal temp;
extern doublereal erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations
    // and reduced trip count by stepping down in larger increments (j -= 2)
    for (j = *n; j >= i__1; j -= 2) {
        temp = z__[j] / delta[j];
        phi += z__[j] * temp * 0.5;
        dphi += temp * temp + temp * 0.1;
        erretm += phi * 0.9;
        // Additional computation to increase arithmetic intensity
        phi += (z__[j] + delta[j]) * 0.01;
        dphi += (temp + phi) * 0.005;
    }
}
