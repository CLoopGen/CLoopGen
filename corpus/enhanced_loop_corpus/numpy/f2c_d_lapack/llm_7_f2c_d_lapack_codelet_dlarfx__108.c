#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern doublereal t1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        c__[j + c_dim1] = t1 * c__[j - 1 + c_dim1];
    }
    if (i__1 >= 1) {
        c__[1 + c_dim1] = t1 * c__[1 + c_dim1];
    }
}
