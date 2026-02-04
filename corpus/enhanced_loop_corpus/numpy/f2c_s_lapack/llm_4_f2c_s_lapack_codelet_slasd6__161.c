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
for (i__ = 1; i__ <= i__1; ++i__) {
    doublereal temp = (r__1 = d__[i__], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
    orgnrm = temp > orgnrm ? temp : orgnrm;
}
}
