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
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    // Trip count halved by stepping down by 2, and additional floating-point operations added to increase workload per iteration
    integer step = 2;
    integer j_start = (*n % 2 == 0) ? *n : *n - 1; // Ensure we start at even index if needed
    for (j = j_start; j >= i__1; j -= step) {
        temp = z__[j] / delta[j];
        phi += z__[j] * temp * 1.5;          // Additional multiplication
        dphi += temp * temp + temp * 0.1;    // Extra additive term
        erretm += phi * 0.9;                 // Damped accumulation
        if (j > i__1) {                      // Safe access
            doublereal cross_temp = z__[j-1] / delta[j-1];
            phi += z__[j-1] * cross_temp * 0.5;
        }
    }
}
