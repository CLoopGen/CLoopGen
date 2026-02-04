#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *indxq;
extern integer *indx;
extern integer *indxc;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer temp[256]; // Local temporary array to eliminate loop-carried dependency
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp[i__ % 256] = indxq[indxc[i__]]; // Break direct dependence on output array
        indx[i__] = temp[i__ % 256];         // Remove RAW hazard by decoupling use of indxc and indx
    }
}
