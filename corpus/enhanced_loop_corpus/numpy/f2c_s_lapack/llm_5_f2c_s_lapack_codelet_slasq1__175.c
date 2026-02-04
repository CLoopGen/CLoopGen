#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *d__;
extern real *e;
extern integer i__1;
extern real r__1;
extern real r__2;
extern real r__3;
extern integer i__;
extern real sigmx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    if (d__[i__] < 0) {
        d__[i__] = -d__[i__];
    }
    real abs_e = e[i__] >= 0 ? e[i__] : -e[i__];
    if (abs_e > sigmx) {
        sigmx = abs_e;
    }
}
}
