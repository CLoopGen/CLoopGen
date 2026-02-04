#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *e;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern doublereal d__3;
extern integer i__;
extern doublereal sigmx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    d__[i__] = d__[i__] < 0 ? -d__[i__] : d__[i__];
    doublereal temp = e[i__] < 0 ? -e[i__] : e[i__];
    sigmx = sigmx > temp ? sigmx : temp;
}
}
