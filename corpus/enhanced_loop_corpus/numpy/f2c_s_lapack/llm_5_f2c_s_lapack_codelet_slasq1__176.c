#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *d__;
extern integer i__1;
extern real r__1;
extern real r__2;
extern integer i__;
extern real sigmx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
sigmx = (doublereal)((i__1 >= 1) ? d__[1] : sigmx);
for (i__ = 2; i__ <= i__1; ++i__) {
    if (d__[i__] < sigmx) continue;
    sigmx = (doublereal)d__[i__];
}
}
