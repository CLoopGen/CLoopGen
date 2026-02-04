#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern integer i__1;
extern integer k;
extern integer mid;
extern integer bsiz2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (mid + bsiz2 <= i__1) {
    for (k = mid + bsiz2; k <= i__1; ++k) {
        for (integer j = 0; j < 1; ++j) {
            z__[k] = 0.F;
        }
    }
}
}
