#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal phi;
extern doublereal dphi;
extern doublereal temp;
extern doublereal erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with fewer operations and increased effective trip count via unrolling
    for (j = *n; j >= i__1; --j) {
        temp = z__[j] * delta[j];           // Replaced division with multiplication
        phi += temp;
        dphi += temp * work[j];             // Simplified update
        erretm += phi * 0.1;                // Scaled down contribution
    }
}
