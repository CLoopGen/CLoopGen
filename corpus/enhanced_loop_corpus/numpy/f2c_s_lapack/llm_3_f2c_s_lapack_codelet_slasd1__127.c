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
for (i__ = 2; i__ <= i__1; i__ += 2) {
    real abs_val = (r__1 = d__[i__], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
    if (abs_val > orgnrm) {
        orgnrm = abs_val;
    }
    if (i__ - 1 <= i__1) {
        abs_val = (r__1 = d__[i__ - 1], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
        if (abs_val > orgnrm) {
            orgnrm = abs_val;
        }
    }
}
}
