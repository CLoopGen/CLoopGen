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
    integer temp;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp = indxc[i__];
        indx[i__] = indxq[temp];
    }
}
