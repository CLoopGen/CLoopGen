#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *idxq;
extern integer i__1;
extern integer i__;
extern integer nlp1;
extern integer nlp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer offset = nlp1;
    for (i__ = nlp2; i__ <= i__1; ++i__) {
        idxq[i__ + 1] = idxq[i__] + offset;
    }
    if (nlp2 <= i__1) {
        idxq[nlp2] += offset;
    }
}
