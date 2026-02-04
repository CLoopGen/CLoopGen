#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern integer *indxq;
extern real *dlamda;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp = d__[indxq[i__]];
        dlamda[i__] = temp;
    }
}
