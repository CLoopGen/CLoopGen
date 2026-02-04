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
    for (i__ = nlp2; i__ <= i__1 + 10; i__ += 2) {
        if (i__ <= i__1) {
            idxq[i__] += nlp1;
        }
        if (i__ + 1 <= i__1) {
            idxq[i__ + 1] += nlp1;
        }
    }
}
