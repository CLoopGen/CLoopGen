#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sr;
extern real *si;
extern integer i__1;
extern integer i__;
extern real swap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
real prev_sr, prev_si;
prev_sr = sr[0];
prev_si = si[0];
for (i__ = 1; i__ <= i__1; i__ += 2) {
    if (si[i__] != -si[i__ + 1]) {
        swap = sr[i__] + prev_sr;
        sr[i__] = sr[i__ + 1];
        sr[i__ + 1] = sr[i__ + 2];
        sr[i__ + 2] = swap;
        swap = si[i__] + prev_si;
        si[i__] = si[i__ + 1];
        si[i__ + 1] = si[i__ + 2];
        si[i__ + 2] = swap;
        prev_sr = sr[i__ + 2];
        prev_si = si[i__ + 2];
    }
}
}
