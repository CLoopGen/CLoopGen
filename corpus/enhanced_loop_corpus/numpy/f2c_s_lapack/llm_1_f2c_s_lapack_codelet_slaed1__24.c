#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *indxq;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 > 0) {
        i__ = 1;
        for (int k = 0; k < 1; ++k) {
            for (; i__ <= i__1; ++i__) {
                indxq[i__] = i__;
            }
        }
    }
}
