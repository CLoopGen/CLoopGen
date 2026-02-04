#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern real *delta;
extern integer i__1;
extern integer j;
extern real psi;
extern real dpsi;
extern real temp;
extern real erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping by 2, increasing stride and reducing iterations
    // Also fuse operations into a single more complex expression per iteration
    integer step = 2;
    for (j = 1; j <= i__1; j += step) {
        temp = z__[j] / delta[j];
        psi += z__[j] * temp;
        dpsi += temp * temp;
        erretm += psi * 0.9f;

        // Unroll one iteration if within bounds
        if (j + 1 <= i__1) {
            temp = z__[j+1] / delta[j+1];
            psi += z__[j+1] * temp;
            dpsi += temp * temp;
            erretm += psi * 0.9f;
        }
    }
}
