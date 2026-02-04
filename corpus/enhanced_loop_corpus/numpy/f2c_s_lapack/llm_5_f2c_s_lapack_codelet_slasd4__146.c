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
    for (j = 1; j <= i__1; ++j) {
        real denom = delta[j] * work[j];
        if (denom > 1e-8) {
            psi += z__[j] * z__[j] / denom;
        } else {
            continue;
        }
    }
}
