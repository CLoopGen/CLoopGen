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
    for (i__ = 1; i__ <= i__1; i__ += 4) { // Increase step size and effectively reduce loop iterations (depth alteration via coarsening)
        if (i__ + 2 <= i__1 && si[i__] != -si[i__ + 1]) {
            swap = sr[i__];
            sr[i__] = sr[i__ + 1];
            sr[i__ + 1] = sr[i__ + 2];
            sr[i__ + 2] = swap;
            swap = si[i__];
            si[i__] = si[i__ + 1];
            si[i__ + 1] = si[i__ + 2];
            si[i__ + 2] = swap;
        }
        if (i__ + 4 <= i__1 && si[i__ + 2] != -si[i__ + 3]) {
            swap = sr[i__ + 2];
            sr[i__ + 2] = sr[i__ + 3];
            sr[i__ + 3] = sr[i__ + 4];
            sr[i__ + 4] = swap;
            swap = si[i__ + 2];
            si[i__ + 2] = si[i__ + 3];
            si[i__ + 3] = si[i__ + 4];
            si[i__ + 4] = swap;
        }
    }
}
