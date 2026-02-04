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
    // Variant 2: Consecutive reverse memory access
    // Traverse the array from high index to low index consecutively
    for (i__ = i__1; i__ >= 1; --i__) {
        coltyp[i__] = 1;
    }
}
