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
    integer temp = nlp1; // Remove loop-carried dependency by caching invariant
    for (i__ = nlp2; i__ <= i__1; ++i__) {
        idxq[i__] = temp; // Eliminate cumulative update, remove RAW/WAW across iterations
        temp += 1; // Introduce independent evolution of temp (loop-local dependency only)
    }
}
