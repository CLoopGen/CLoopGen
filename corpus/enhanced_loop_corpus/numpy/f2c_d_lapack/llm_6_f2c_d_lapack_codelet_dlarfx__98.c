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
    doublereal temp;
    for (j = 1; j <= i__1; ++j) {
        temp = c__[j * c_dim1 + 1];
        c__[j * c_dim1 + 1] = t1 * temp;
    }
}
