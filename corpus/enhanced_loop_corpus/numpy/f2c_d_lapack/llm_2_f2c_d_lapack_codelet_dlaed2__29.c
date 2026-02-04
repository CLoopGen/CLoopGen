#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *coltyp;
extern integer i__1;
extern integer i__;
extern integer n1p1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element starting from n1p1)
    for (i__ = n1p1; i__ <= i__1; i__ += 2) {
        coltyp[i__] = 3;
    }
    // Handle remaining element if range includes an odd number of elements
    if ((i__1 - n1p1 + 1) % 2 != 0 && i__1 >= n1p1) {
        coltyp[i__1] = 3;
    }
}
