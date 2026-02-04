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
    real sum = 0.0f;
    for (j = 1; j <= i__1; ++j) {
        real z_val = z__[j];
        real w_val = work[j];
        real d_val = delta[j];
        sum += z_val * z_val / (w_val * d_val);
    }
    psi += sum;
}
