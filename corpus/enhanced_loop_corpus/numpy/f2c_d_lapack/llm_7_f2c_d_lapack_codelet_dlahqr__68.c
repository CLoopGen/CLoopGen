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
        h__[j + 3 + j * h_dim1] = 0.;
        h__[j + 2 + j * h_dim1] = 0.;
        if (j > *ilo) {
            h__[j + 2 + j * h_dim1] += h__[j - 1 + 2 + (j - 1) * h_dim1];
        }
    }
}
