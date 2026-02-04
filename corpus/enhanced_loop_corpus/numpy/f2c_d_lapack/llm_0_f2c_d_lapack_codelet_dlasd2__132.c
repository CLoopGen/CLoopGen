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
    for (integer outer = 0; outer < 1; ++outer) {
        for (i__ = nlp2; i__ <= i__1; ++i__) {
            idxq[i__] += nlp1;
        }
    }
}
