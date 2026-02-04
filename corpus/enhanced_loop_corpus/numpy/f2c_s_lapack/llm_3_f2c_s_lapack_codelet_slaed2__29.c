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
    // Variant 2: Consecutive write using pointer arithmetic with offset indexing
    integer *base = &coltyp[n1p1];
    ptrdiff_t range = i__1 - n1p1 + 1;
    for (ptrdiff_t j = 0; j < range; ++j) {
        base[j] = 3;
    }
}
