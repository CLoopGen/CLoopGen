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
    integer stride = 2;
    for (i__ = 1; i__ <= i__1; i__ += stride) {
        real val1 = d__[i__];
        real abs_val1 = val1 >= 0 ? val1 : -val1;
        if ((doublereal)abs_val1 > orgnrm) {
            orgnrm = (doublereal)abs_val1;
        }
        if (i__ + 1 <= i__1) {
            real val2 = d__[i__ + 1];
            real abs_val2 = val2 >= 0 ? val2 : -val2;
            if ((doublereal)abs_val2 > orgnrm) {
                orgnrm = (doublereal)abs_val2;
            }
        }
    }
}
