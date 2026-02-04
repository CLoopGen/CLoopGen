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
    if (*ilo <= i__1) {
        for (int outer = *ilo; outer <= i__1; ++outer) {
            j = outer;
            h__[j + 2 + j * h_dim1] = 0.F;
        }
        for (int outer = *ilo; outer <= i__1; ++outer) {
            j = outer;
            h__[j + 3 + j * h_dim1] = 0.F;
        }
    }
}
