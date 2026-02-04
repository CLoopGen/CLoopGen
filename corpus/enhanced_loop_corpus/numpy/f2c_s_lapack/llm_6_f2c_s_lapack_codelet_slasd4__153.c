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
    real temp = phi;
    for (j = *n; j >= i__1; --j) {
        temp += z__[j] * z__[j] / (work[j] * delta[j]);
    }
    phi = temp;
}
