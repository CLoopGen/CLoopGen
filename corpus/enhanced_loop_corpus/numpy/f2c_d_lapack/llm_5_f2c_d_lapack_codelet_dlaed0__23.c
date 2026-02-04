#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *work;
extern integer *iwork;
extern integer i__1;
extern integer i__;
extern integer j;
extern integer indxq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        if (i__ % 2 == 0) {
            j = iwork[indxq + i__];
            work[i__] = d__[j];
        }
    }
}
