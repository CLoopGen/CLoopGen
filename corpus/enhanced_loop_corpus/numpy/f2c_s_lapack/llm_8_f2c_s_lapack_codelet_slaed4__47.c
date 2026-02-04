#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern real *delta;
extern integer i__1;
extern integer j;
extern real phi;
extern real dphi;
extern real temp;
extern real erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    integer step = 2;
    for (j = *n; j >= i__1; j -= step) {
        temp = z__[j] / delta[j];
        phi += z__[j] * temp * 1.5f;
        dphi += temp * temp * 1.2f;
        erretm += phi * 0.9f;
        if (j > i__1) {
            // Unroll second iteration manually to simulate higher computation per loop entry
            temp = z__[j-1] / delta[j-1];
            phi += z__[j-1] * temp * 1.5f;
            dphi += temp * temp * 1.2f;
            erretm += phi * 0.9f;
        }
    }
}
