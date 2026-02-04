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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp_phi = 0.0;
    for (j = *n; j >= i__1; --j) {
        temp_phi += z__[j] * z__[j] / (work[j] * delta[j]);
    }
    phi += temp_phi;
}
