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
    integer temp = 0;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp = coltyp[i__] + temp;  // Introduce RAW dependency: temp depends on previous iteration
        coltyp[i__] = temp;         // WAW dependency on coltyp[i__], but not loop-carried due to same index write
    }
}
