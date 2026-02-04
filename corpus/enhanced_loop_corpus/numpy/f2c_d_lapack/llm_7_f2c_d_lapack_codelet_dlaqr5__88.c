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
    doublereal prev_swap_sr = 0.0, prev_swap_si = 0.0;
    int first_iteration = 1;
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        if (si[i__] != -si[i__ + 1]) {
            swap = sr[i__];
            sr[i__] = sr[i__ + 1];
            sr[i__ + 1] = sr[i__ + 2];
            if (!first_iteration) {
                sr[i__ + 2] = prev_swap_sr;
            }
            prev_swap_sr = swap;

            swap = si[i__];
            si[i__] = si[i__ + 1];
            si[i__ + 1] = si[i__ + 2];
            if (!first_iteration) {
                si[i__ + 2] = prev_swap_si;
            }
            prev_swap_si = swap;

            first_iteration = 0;
        }
    }
}
