#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern integer i__1;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 2; k <= i__1; ++k) {
        z__[k] = z__[(k << 2) - 3];
        z__[k + 1] = z__[k]; // Introduce WAW and RAW dependency: z__[k] written before used in next iteration
    }
}
