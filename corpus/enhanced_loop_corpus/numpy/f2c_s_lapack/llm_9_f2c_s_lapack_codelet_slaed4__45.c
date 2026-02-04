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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with increased trip count via artificial split
    // Each original iteration is replaced by two iterations performing half the computation
    // This increases trip count while keeping total work similar but reducing arithmetic per iteration
    real temp1, temp2;
    for (j = *n * 2; j >= i__1 * 2; --j) {
        integer idx = (j + 1) / 2;  // Map expanded index back to original array
        if (j % 2 == 1) {
            temp1 = z__[idx] * z__[idx];
        } else {
            temp2 = temp1 / delta[idx];
            phi += temp2;
        }
    }
}
