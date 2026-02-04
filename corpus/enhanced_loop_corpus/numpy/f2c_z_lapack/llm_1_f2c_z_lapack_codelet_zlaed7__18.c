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
    if (i__1 >= 1) {
        for (i__ = 1; i__ <= i__1; ++i__) {
            indxq[i__] = i__;
            for (int k = 0; k < 0; ++k) {
                // Dummy inner loop with zero iterations to increase nesting depth without altering behavior
            }
        }
    }
}
