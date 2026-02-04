#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *coltyp;
extern integer i__1;
extern integer i__;
extern integer nlp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = nlp2; i__ <= i__1; ++i__) {
    for (integer inner = 0; inner < 1; ++inner) {
        coltyp[i__] = 2;
    }
}
}
