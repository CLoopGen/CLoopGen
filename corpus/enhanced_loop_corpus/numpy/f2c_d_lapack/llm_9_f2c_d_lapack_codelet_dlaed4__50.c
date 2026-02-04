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
    // Variant 2: Reduced computational intensity with increased trip count via unrolling the original logic into smaller steps
    // Simulate higher trip count by iterating more times with minimal work per iteration
    // Here, we process each element twice with split operations to dilute computation per iteration
    for (j = *n * 2; j >= i__1 * 2; --j) {
        integer idx = (j + 1) / 2;  // Map expanded index back to original array
        if (j % 2 == 1) {
            // First pass: compute temp and partial phi
            temp = z__[idx] / delta[idx];
            phi += z__[idx] * temp * 0.5;  // Half contribution
        } else {
            // Second pass: complete dphi and erretm updates
            dphi += temp * temp;
            erretm += phi * 0.5;           // Accumulate half of updated phi
        }
    }
}
