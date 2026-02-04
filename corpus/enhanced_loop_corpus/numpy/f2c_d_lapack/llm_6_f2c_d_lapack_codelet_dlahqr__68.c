#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *ilo;
extern doublereal *h__;
extern integer h_dim1;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer temp1, temp2;
    for (j = *ilo; j <= i__1; ++j) {
        temp1 = j + 2 + j * h_dim1;
        temp2 = j + 3 + j * h_dim1;
        h__[temp1] = 0.;
        h__[temp2] = 0.;
    }
}
