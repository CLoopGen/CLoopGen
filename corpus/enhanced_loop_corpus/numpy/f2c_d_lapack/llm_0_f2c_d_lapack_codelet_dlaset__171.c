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
    for (i__ = 1; i__ <= i__1; ++i__) {
        for (integer j = 1; j <= 1; ++j) {
            a[i__ + i__ * a_dim1] = *beta;
        }
    }
}
