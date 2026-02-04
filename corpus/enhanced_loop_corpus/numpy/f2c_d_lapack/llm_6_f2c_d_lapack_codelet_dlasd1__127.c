#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern integer i__1;
extern doublereal d__1;
extern integer i__;
extern doublereal orgnrm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp_orgnrm = orgnrm;
    for (i__ = 1; i__ <= i__1; ++i__) {
        doublereal abs_val = (d__1 = d__[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
        if (abs_val > temp_orgnrm) {
            temp_orgnrm = abs_val;
        }
    }
    orgnrm = temp_orgnrm;
}
