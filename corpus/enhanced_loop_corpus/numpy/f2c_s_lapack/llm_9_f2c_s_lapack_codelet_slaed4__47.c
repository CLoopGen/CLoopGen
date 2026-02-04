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
    // Variant 2: Reduced computational intensity with simplified operations and increased effective trip count via finer increments
    for (j = *n; j >= i__1; --j) {
        temp = z__[j] * delta[j];  // Replaced division with multiplication for lower cost
        phi += temp;               // Simplified accumulation
        dphi += temp;              // Reduced operation complexity
        erretm += phi * 0.1f;      // Scaled down contribution to error term
    }
}
