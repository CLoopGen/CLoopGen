#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *work;
extern integer i__1;
extern real r__1;
extern real r__2;
extern integer i__;
extern real value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 >= 1) {
    value = (doublereal)work[1];
    for (i__ = 2; i__ <= i__1; ++i__) {
        if (work[i__] > value) {
            value = (doublereal)work[i__];
        }
    }
}
}
