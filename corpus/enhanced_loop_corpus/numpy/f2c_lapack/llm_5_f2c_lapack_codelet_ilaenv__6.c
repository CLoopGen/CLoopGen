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
for (i__ = 2; i__ <= 6; ++i__) {
    ic = *(unsigned char *)&subnam[i__ - 1];
    int inRange = 0;
    if (ic >= 129 && ic <= 137) inRange = 1;
    else if (ic >= 145 && ic <= 153) inRange = 1;
    else if (ic >= 162 && ic <= 169) inRange = 1;
    if (inRange) {
        *(unsigned char *)&subnam[i__ - 1] = (char)(ic + 64);
    }
}
}
