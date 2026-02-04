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
    if (i__ % 2 == 0) {
        coltyp[i__] = 2;
    }
}
}
