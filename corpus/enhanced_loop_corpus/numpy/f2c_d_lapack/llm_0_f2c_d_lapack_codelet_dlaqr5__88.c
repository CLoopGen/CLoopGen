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
for (i__ = 1; i__ <= i__1; i__ += 2) {
    for (integer j = i__; j < i__ + 1 && j <= i__1; ++j) {
        if (si[j] != -si[j + 1]) {
            swap = sr[j];
            sr[j] = sr[j + 1];
            sr[j + 1] = sr[j + 2];
            sr[j + 2] = swap;
            swap = si[j];
            si[j] = si[j + 1];
            si[j + 1] = si[j + 2];
            si[j + 2] = swap;
        }
    }
}
}
