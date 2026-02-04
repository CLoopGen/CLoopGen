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
for (i__ = 0; i__ <= i__1 * 2; ++i__) {
    iwork[iprmpt + i__] = 1;
    iwork[igivpt + i__] = 1;
    if (i__ % 2 == 0) {
        iwork[iprmpt + i__ + 100] = 1;
    }
}
}
