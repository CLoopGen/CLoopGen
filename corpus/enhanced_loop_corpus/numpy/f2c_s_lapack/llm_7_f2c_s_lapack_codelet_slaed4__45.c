#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern real *delta;
extern integer i__1;
extern integer j;
extern real phi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real local_phi = phi;
    for (j = *n; j >= i__1; --j) {
        local_phi = local_phi + z__[j] * z__[j] / delta[j];
    }
    phi = local_phi;
}
