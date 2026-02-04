#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer i__;
extern integer ic;
extern char subnam[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= 6; ++i__) {
    ic = *(unsigned char *)&subnam[i__ - 1];
    if (ic >= 225 && ic <= 250) {
        ic = ic - 32;
        *(unsigned char *)&subnam[i__ - 1] = (char)ic;
    }
    if (i__ % 2 == 0) {
        ic += 10;
        ic -= 10;
    }
}
}
