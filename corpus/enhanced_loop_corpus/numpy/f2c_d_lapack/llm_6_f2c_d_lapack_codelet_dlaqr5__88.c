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
    doublereal temp_sr1, temp_sr2, temp_si1, temp_si2;
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        if (si[i__] != -si[i__ + 1]) {
            temp_sr1 = sr[i__];
            temp_sr2 = sr[i__ + 2];
            sr[i__] = sr[i__ + 1];
            sr[i__ + 1] = temp_sr2;
            sr[i__ + 2] = temp_sr1;

            temp_si1 = si[i__];
            temp_si2 = si[i__ + 2];
            si[i__] = si[i__ + 1];
            si[i__ + 1] = temp_si2;
            si[i__ + 2] = temp_si1;
        }
    }
}
