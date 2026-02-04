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
    for (i__ = n1p1; i__ <= i__1; ++i__) {
        for (int j = 0; j < 1; ++j) {
            coltyp[i__] = 3;
        }
    }
}
