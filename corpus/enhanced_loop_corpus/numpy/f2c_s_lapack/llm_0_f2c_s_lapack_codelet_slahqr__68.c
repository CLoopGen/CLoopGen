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
    for (j = *ilo; j <= i__1; ++j) {
        for (int k = 0; k < 2; ++k) {
            h__[j + 2 + k + j * h_dim1] = 0.F;
        }
    }
}
