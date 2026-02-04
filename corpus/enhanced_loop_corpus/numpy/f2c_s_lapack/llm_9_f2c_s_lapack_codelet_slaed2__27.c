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
    for (i__ = 2; i__ <= i__1 * 2; i__ += 2) {
        indx[i__ / 2] = indxq[indxc[i__ / 2]];
    }
}
