#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *q;
extern integer q_dim1;
extern integer i__1;
extern integer i__;
extern integer ktemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count and simplified access pattern with minimal arithmetic
    integer i__;
    for (i__ = 1; i__ <= i__1 / 2; ++i__) {
        q[i__ + ktemp * q_dim1] = q[i__ + q_dim1];
    }
}
