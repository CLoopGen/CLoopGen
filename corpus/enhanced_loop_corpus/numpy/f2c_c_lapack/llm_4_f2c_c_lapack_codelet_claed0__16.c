#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *iwork;
extern integer i__1;
extern integer i__;
extern integer igivpt;
extern integer iprmpt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 0; i__ <= i__1; ++i__) {
    if ((i__ & 1) == 0) {
        iwork[iprmpt + i__] = 1;
    } else {
        iwork[igivpt + i__] = 1;
    }
}
}
