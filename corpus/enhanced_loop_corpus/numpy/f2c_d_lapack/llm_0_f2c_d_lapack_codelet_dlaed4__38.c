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
    for (integer k = 1; k <= i__1; ++k) {
        for (j = k; j <= k; ++j) {
            psi += z__[j] * z__[j] / delta[j];
        }
    }
}
