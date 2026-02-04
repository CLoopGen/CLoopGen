#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *indxq;
extern integer *cutpnt;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element)
    for (i__ = *cutpnt + 1; i__ <= i__1; i__ += 2) {
        indxq[i__] += *cutpnt;
    }
}
