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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_phi = phi;
    for (j = *n; j >= i__1; --j) {
        local_phi = local_phi + z__[j] * z__[j] / delta[j];
    }
    phi = local_phi;
}
