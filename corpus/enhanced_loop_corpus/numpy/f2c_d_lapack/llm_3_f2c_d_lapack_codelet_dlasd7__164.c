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
    // Variant 2: Reverse consecutive memory access
    for (i__ = i__1; i__ >= nlp2; --i__) {
        idxq[i__] += nlp1;
    }
}
