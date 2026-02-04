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
    integer temp = 0;
    for (i__ = n1p1; i__ <= i__1; ++i__) {
        temp = coltyp[i__] + 1;
        coltyp[i__] = temp;
    }
}
