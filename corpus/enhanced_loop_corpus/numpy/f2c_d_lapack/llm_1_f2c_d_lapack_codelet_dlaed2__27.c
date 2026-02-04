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
    if (i__1 >= 1) {
        for (int k = 1; k <= i__1; ++k) {
            indx[k] = indxq[indxc[k]];
        }
    }
}
