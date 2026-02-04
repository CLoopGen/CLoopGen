#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *work;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp = 0.0F;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp += work[i__];
        work[i__] = temp;
    }
}
