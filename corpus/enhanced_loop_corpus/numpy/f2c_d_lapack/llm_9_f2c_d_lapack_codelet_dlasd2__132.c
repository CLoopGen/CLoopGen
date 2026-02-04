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
    for (i__ = nlp2; i__ <= i__1 + (i__1 - nlp2); ++i__) {
        if (i__ <= i__1) {
            idxq[i__] += nlp1;
        } else {
            integer offset = i__ - i__1;
            idxq[i__ - offset * 2] += nlp1 * 2;
        }
    }
}
