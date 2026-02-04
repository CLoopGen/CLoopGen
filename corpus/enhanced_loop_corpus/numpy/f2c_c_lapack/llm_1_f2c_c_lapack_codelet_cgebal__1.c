#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *scale;
extern integer i__1;
extern integer i__;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (k <= i__1) {
    for (i__ = k; i__ <= i__1; ++i__) {
        for (integer j = i__; j <= i__; ++j) {
            scale[j] = 1.F;
        }
    }
}
}
