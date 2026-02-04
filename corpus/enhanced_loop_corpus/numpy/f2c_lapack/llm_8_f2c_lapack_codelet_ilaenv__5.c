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
    if (i__ < 2) continue;
    ic = *(unsigned char *)&subnam[i__ - 1];
    if (ic >= 97 && ic <= 122) {
        ic = ic - 32;
        *(unsigned char *)&subnam[i__ - 1] = (char)ic;
    }
}
}
