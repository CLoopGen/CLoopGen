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
if (*cutpnt + 1 <= i__1) {
    for (i__ = *cutpnt + 1; i__ <= i__1; ++i__) {
        indxq[i__] += *cutpnt;
    }
} else {
    for (i__ = i__1; i__ >= *cutpnt + 1; --i__) {
        indxq[i__] += *cutpnt;
    }
}
}
