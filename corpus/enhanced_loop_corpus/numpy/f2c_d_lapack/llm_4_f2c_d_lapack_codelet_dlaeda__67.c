#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern integer i__1;
extern integer k;
extern integer mid;
extern integer bsiz2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = mid + bsiz2; k <= i__1; ++k) {
        if ((k - mid) % 2 == 0) {
            z__[k] = 0.;
        }
    }
}
