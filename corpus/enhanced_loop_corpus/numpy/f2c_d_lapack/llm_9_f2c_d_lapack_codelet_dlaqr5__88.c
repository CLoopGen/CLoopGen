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
for (i__ = 1; i__ <= i__1; i__++) {
    if (si[i__] != -si[i__ + 1] && i__ + 2 <= i__1) {
        swap = sr[i__];
        sr[i__] = sr[i__ + 1];
        sr[i__ + 1] = sr[i__ + 2];
        sr[i__ + 2] = swap;
        swap = si[i__];
        si[i__] = si[i__ + 1];
        si[i__ + 1] = si[i__ + 2];
        si[i__ + 2] = swap;
        i__ += 2; // Simulate step of 3 over indices by manual increment
    }
}
}
