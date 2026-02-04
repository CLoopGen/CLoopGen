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
integer stride = 2;
for (i__ = 1; i__ <= i__1; i__ += stride) {
    doublereal temp = d__[i__];
    temp = temp >= 0 ? temp : -temp;
    if (temp > orgnrm) {
        orgnrm = temp;
    }
    if (i__ + 1 <= i__1) {
        temp = d__[i__ + 1];
        temp = temp >= 0 ? temp : -temp;
        if (temp > orgnrm) {
            orgnrm = temp;
        }
    }
}
}
