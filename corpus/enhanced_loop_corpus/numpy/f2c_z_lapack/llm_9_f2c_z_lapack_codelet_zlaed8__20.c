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
for (i__ = *cutpnt + 1; i__ <= i__1; i__ += 2) {
    if (i__ <= i__1) {
        indxq[i__] += *cutpnt;
    }
    if (i__ + 1 <= i__1) {
        indxq[i__ + 1] += *cutpnt;
        indxq[i__ + 1] += *cutpnt;
    }
}
}
