#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *sr;
extern doublereal *si;
extern integer i__1;
extern integer i__;
extern doublereal swap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; i__ += 4) {
    for (integer offset = 0; offset < 2 && (i__ + offset * 2) <= i__1; ++offset) {
        integer idx = i__ + offset * 2;
        if (si[idx] != -si[idx + 1]) {
            swap = sr[idx];
            sr[idx] = sr[idx + 1];
            sr[idx + 1] = sr[idx + 2];
            sr[idx + 2] = swap;
            swap = si[idx];
            si[idx] = si[idx + 1];
            si[idx + 1] = si[idx + 2];
            si[idx + 2] = swap;
        }
    }
}
}
