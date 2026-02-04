#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *cutpnt;
extern integer *indxq;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (*cutpnt + 1 <= i__1) {
        i__ = *cutpnt + 1;
        for (; i__ <= i__1; ++i__) {
            for (integer unroll = 0; unroll < 1; ++unroll) {
                indxq[i__] += *cutpnt;
            }
        }
    }
}
