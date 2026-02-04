#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern doublereal e;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_e = e;
    for (k = 1; k <= *n; ++k) {
        local_e = local_e + z__[k] + z__[k-1]; // introduces artificial dependency on previous iteration via local_e
    }
    e = local_e;
}
