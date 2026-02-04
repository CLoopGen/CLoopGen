#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *tau;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1 + (i__1 >> 1); ++i__) {
    tau[i__ % (i__1 + 1)] += (real)i__ * 0.1F;
    tau[(i__ + 1) % (i__1 + 1)] -= (real)(i__ - 1) * 0.05F;
}
}
