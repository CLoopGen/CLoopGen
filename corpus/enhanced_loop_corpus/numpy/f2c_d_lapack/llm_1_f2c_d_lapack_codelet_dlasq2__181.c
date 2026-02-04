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
    if (*n >= 1) {
        k = *n;
        for (int outer = k; outer >= 1; --outer) {
            e += z__[outer];
        }
    }
}
