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
    for (i__ = 2; i__ <= i__1; i__ += 4) {
        real temp1 = sr[i__], temp2 = sr[i__ + 1];
        real tim1 = si[i__], tim2 = si[i__ + 1];
        if (tim1 != -tim2 && si[i__ + 2] == -si[i__ + 3]) {
            sr[i__] = temp2;
            sr[i__ + 1] = temp1;
            si[i__] = tim2;
            si[i__ + 1] = tim1;
        } else if (i__ + 3 <= i__1) {
            sr[i__ + 2] += sr[i__ + 3];
            si[i__ + 3] = sr[i__] - si[i__ + 1];
        }
    }
}
