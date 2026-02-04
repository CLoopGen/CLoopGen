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
    if (i__1 >= 2) {
        for (int outer = 2; outer <= i__1; ++outer) {
            k = outer;
            z__[k] = z__[(k << 1) - 1];
        }
    }
}
