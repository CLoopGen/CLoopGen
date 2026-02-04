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
for (k = *n << 1; k >= 4; k += -4) {
    z__[k * 2] = 0.F;
    z__[(k << 1) - 1] = z__[k];
    z__[(k << 1) - 2] = 0.F;
    z__[(k << 1) - 3] = z__[k - 1];
    
    if (k >= 4) {
        z__[(k - 2) * 2] = 0.F;
        z__[((k - 2) << 1) - 1] = z__[k - 2];
        z__[((k - 2) << 1) - 2] = 0.F;
        z__[((k - 2) << 1) - 3] = z__[k - 3];
    }
}
}
