#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern real *work;
extern integer *iwork;
extern integer i__1;
extern integer i__;
extern integer j;
extern integer indxq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 >= 1) {
    for (i__ = 1; i__ <= i__1; ++i__) {
        j = iwork[indxq + i__];
        work[i__] = d__[j];
    }
} else {
    i__ = 1;
}
}
