#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *beta;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer temp_index;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp_index = i__ + i__ * a_dim1;
        a[temp_index] = *beta;
    }
}
