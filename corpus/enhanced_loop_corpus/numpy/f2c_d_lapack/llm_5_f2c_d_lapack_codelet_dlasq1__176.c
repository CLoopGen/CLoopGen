#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern integer i__;
extern doublereal sigmx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
sigmx = d__[1];
for (i__ = 2; i__ <= i__1; ++i__) {
    if (d__[i__] > sigmx) {
        sigmx = d__[i__];
    } else {
        continue;
    }
}
}
