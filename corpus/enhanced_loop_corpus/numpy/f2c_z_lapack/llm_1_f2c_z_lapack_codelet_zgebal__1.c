#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *scale;
extern integer i__1;
extern integer i__;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (k <= i__1) {
    for (i__ = k; i__ <= i__1; ++i__) {
        for (int j = 0; j < 2; ++j) {
            if (j == 0) {
                scale[i__] = 1.;
            }
        }
    }
}
}
