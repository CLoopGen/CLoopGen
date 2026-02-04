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
extern integer i__;
extern real orgnrm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int updated = 1;
for (i__ = 1; i__ <= i__1 && updated; ++i__) {
    updated = 0;
    doublereal abs_val = (r__1 = d__[i__], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
    if (abs_val > orgnrm) {
        orgnrm = abs_val;
        updated = 1;
    }
}
}
