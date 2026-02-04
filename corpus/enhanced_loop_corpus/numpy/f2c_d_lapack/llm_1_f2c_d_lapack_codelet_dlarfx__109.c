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
extern doublereal t2;
extern doublereal v1;
extern doublereal v2;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (integer k = 0; k < 1; ++k) {
        for (j = 1; j <= i__1; ++j) {
            sum = v1 * c__[j + c_dim1] + v2 * c__[j + (c_dim1 << 1)];
            c__[j + c_dim1] -= sum * t1;
            c__[j + (c_dim1 << 1)] -= sum * t2;
        }
    }
}
