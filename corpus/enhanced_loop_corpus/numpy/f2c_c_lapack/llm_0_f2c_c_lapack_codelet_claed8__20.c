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
for (integer outer = 0; outer < 1; ++outer) {
    for (i__ = *cutpnt + 1; i__ <= i__1; ++i__) {
        indxq[i__] += *cutpnt;
    }
}
}
