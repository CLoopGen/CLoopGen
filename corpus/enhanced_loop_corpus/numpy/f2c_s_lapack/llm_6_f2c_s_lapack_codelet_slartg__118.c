#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *r__;
extern integer i__1;
extern integer i__;
extern real safmx2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp = *r__;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp *= safmx2;
    }
    *r__ = temp;
}
