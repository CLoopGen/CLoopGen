#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = *n << 1; k >= 2; k += -2) {
        if (k % 4 == 0) {
            z__[k * 2] = 0.;
            z__[(k << 1) - 1] = z__[k];
        } else {
            z__[(k << 1) - 2] = 0.;
            z__[(k << 1) - 3] = z__[k - 1];
        }
    }
}
