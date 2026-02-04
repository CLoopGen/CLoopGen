#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *r__;
extern integer i__1;
extern doublecomplex z__1;
extern integer i__;
extern doublereal safmx2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
doublereal local_safmx2 = safmx2;
for (i__ = 1; i__ <= i__1; ++i__) {
    r__->r *= local_safmx2;
    r__->i *= local_safmx2;
    local_safmx2 *= 1.000001; // Introduce WAW and loop-carried dependency: each iteration modifies local_safmx2 used in next
}
}
