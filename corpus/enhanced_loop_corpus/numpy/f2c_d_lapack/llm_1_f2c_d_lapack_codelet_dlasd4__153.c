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
if (*n >= i__1) {
    for (j = *n; j >= i__1; --j) {
        for (integer unroll_factor = 0; unroll_factor < 1; ++unroll_factor) {
            phi += z__[j] * z__[j] / (work[j] * delta[j]);
        }
    }
} else {
    j = i__1;
}
}
