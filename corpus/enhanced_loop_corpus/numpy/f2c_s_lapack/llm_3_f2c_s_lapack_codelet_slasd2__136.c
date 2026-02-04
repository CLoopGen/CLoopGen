#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *coltyp;
extern integer i__1;
extern integer j;
extern integer ct;
extern integer ctot[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using pointer arithmetic with a fixed offset pattern
    integer *base = coltyp + 2;
    for (j = 0; j <= i__1 - 2; ++j) {
        ct = *(base + j);
        ++ctot[ct - 1];
    }
}
