#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *r__;
extern integer i__1;
extern integer i__;
extern doublereal safmx2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 > 0) {
    for (i__ = 1; i__ <= i__1; ++i__) {
        for (int j = 0; j < 1; ++j) {
            *r__ *= safmx2;
        }
    }
}
}
