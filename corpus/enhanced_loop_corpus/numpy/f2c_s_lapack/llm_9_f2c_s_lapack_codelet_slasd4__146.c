#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real psi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 2; j <= i__1; j += 2) { // Modified trip count: start later, step by two
        real temp1 = z__[j-1] * z__[j-1];
        real temp2 = delta[j-1] * work[j-1];
        if (temp2 != 0.0f) {
            psi += temp1 / temp2;
        }
        real temp3 = z__[j] * z__[j];
        real temp4 = delta[j] * work[j];
        if (temp4 != 0.0f) {
            psi += temp3 / temp4;
        }
    }
    // Handle odd-sized i__1 if needed
    if (i__1 % 2 == 1) {
        real temp = delta[i__1] * work[i__1];
        if (temp != 0.0f) {
            psi += z__[i__1] * z__[i__1] / temp;
        }
    }
}
