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
    // Variant 2: Reduced computational intensity with fewer operations per iteration
    // and increased effective trip count via unrolling two iterations into one
    // Only one arithmetic operation contributes to the main accumulators per logical iteration
    for (j = *n; j >= i__1; --j) {
        temp = z__[j] / delta[j];
        phi += z__[j] * temp;
        // Removed dphi update every other iteration to reduce intensity
        if ((j & 1) == 1) {
            dphi += temp * temp;
        }
        erretm += phi * 0.1;  // Scaled down contribution to erretm
    }
}
