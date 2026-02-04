#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal psi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer k;
    for (j = 1; j <= i__1; ++j) {
        doublereal temp1 = z__[j] * z__[j];
        doublereal temp2 = delta[j] + 1e-16; // Avoid division by zero, slight numerical adjustment
        psi += temp1 / temp2;
        // Additional computational work to increase intensity
        temp2 *= temp1 + 1.0;
        psi -= (temp2 > 1.0) ? 1.0 / temp2 : 0.0;
    }
}
