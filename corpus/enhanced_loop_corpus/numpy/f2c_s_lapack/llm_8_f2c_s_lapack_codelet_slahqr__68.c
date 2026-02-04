#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *ilo;
extern real *h__;
extern integer h_dim1;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *ilo; j <= i__1 + 2; ++j) {
    h__[j + 2 + j * h_dim1] = 0.F;
    h__[j + 3 + j * h_dim1] = 0.F;
    if (j > *ilo) {
        h__[j - 1 + j * h_dim1] = 0.F;
    }
}
}
