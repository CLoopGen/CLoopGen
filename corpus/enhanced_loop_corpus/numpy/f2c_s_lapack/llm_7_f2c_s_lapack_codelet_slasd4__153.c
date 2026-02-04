#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real phi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real accumulator = 0.0f;
    for (j = *n; j >= i__1; --j) {
        real z_val = z__[j];
        real w_val = work[j];
        real d_val = delta[j];
        accumulator += z_val * z_val / (w_val * d_val);
    }
    phi += accumulator;
}
