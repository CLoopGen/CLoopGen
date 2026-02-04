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
    // Variant 2: Strided memory access with increased stride, accessing every other relevant element
    for (j = *ilo; j <= i__1; j += 2) {
        if (j <= i__1) {
            h__[j + 2 + j * h_dim1] = 0.F;
            h__[j + 3 + j * h_dim1] = 0.F;
        }
        if (j + 1 <= i__1) {
            h__[j + 1 + 2 + (j + 1) * h_dim1] = 0.F;
            h__[j + 1 + 3 + (j + 1) * h_dim1] = 0.F;
        }
    }
}
