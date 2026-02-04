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
        real temp = d__[i__];
        doublereal abs_val = (doublereal)((temp >= 0.0f) ? temp : -temp);
        if (abs_val > orgnrm) {
            orgnrm = abs_val;
        }
    }
}
