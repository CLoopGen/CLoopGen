#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = *n << 1; k >= 2; k += -2) {
        real temp1 = z__[k];
        real temp2 = z__[k - 1];
        z__[(k << 1) - 3] = temp2;
        z__[(k << 1) - 1] = temp1;
        z__[k * 2] = 0.F;
        z__[(k << 1) - 2] = 0.F;
    }
}
