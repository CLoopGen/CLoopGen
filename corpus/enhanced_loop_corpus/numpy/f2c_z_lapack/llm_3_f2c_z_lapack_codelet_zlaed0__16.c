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
    ptrdiff_t idx1 = iprmpt + i__;
    ptrdiff_t idx2 = igivpt + i__;
    iwork[idx1] = 1;
    iwork[idx2] = 1;
}
}
