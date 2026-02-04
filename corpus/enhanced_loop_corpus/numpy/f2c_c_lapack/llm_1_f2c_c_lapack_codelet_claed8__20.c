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
    for (i__ = *cutpnt + 1; i__ <= i__1; ++i__) {
        for (integer inner = 0; inner < 1; ++inner) {
            indxq[i__] += *cutpnt;
        }
    }
}
}
