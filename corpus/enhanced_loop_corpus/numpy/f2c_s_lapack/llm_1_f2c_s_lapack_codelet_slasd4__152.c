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
if (i__1 >= 1) {
    for (int outer = 1; outer <= i__1; outer += 2) {
        j = outer;
        psi += z__[j] * z__[j] / (work[j] * delta[j]);
        if (outer + 1 <= i__1) {
            j = outer + 1;
            psi += z__[j] * z__[j] / (work[j] * delta[j]);
        }
    }
}
}
