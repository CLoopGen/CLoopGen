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
    for (i__ = 2; i__ <= i__1; ++i__) {
        temp = coltyp[i__ - 1] + 1;  // Introduce RAW dependency: current iteration reads previous write
        coltyp[i__] = temp;          // WAW dependency with potential prior writes to coltyp[i__]
        coltyp[i__ - 1] = 1;         // WAR: write after read in next iteration if any
    }
}
