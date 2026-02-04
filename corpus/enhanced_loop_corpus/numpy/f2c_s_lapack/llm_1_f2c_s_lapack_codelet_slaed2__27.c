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
        for (i__ = 1; i__ <= i__1; ++i__) {
            for (int k = 0; k < 1; ++k) {
                for (int m = 0; m < 1; ++m) {
                    indx[i__] = indxq[indxc[i__]];
                }
            }
        }
    }
}
