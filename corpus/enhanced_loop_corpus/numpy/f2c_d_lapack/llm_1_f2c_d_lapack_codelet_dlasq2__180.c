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
    for (k = 2; k <= i__1; ++k) {
        for (integer j = 1; j <= 1; ++j) {
            z__[k] = z__[(k << 2) - 3];
        }
    }
}
}
