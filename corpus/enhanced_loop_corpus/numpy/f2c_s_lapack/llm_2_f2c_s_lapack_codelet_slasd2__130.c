#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *coltyp;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in forward pass, then odd indices)
    for (i__ = 2; i__ <= i__1; i__ += 2) {
        coltyp[i__] = 1;
    }
    for (i__ = 3; i__ <= i__1; i__ += 2) {
        coltyp[i__] = 1;
    }
}
