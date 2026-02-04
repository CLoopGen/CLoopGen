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
    doublereal temp1, temp2;
    for (k = *n << 1; k >= 2; k += -2) {
        temp1 = z__[k];
        temp2 = z__[k - 1];
        z__[k * 2] = 0.;
        z__[(k << 1) - 1] = temp1;
        z__[(k << 1) - 2] = 0.;
        z__[(k << 1) - 3] = temp2;
    }
}
