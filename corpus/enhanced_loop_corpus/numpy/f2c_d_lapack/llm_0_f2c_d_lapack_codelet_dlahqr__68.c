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
for (j = *ilo; j <= i__1; ++j) {
    for (int k = 2; k <= 3; ++k) {
        h__[j + k + j * h_dim1] = 0.;
    }
}
}
