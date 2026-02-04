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
    for (integer j = 0; j < 2; ++j) {
        if (j == 0) {
            iwork[iprmpt + i__] = 1;
        } else {
            iwork[igivpt + i__] = 1;
        }
    }
}
}
