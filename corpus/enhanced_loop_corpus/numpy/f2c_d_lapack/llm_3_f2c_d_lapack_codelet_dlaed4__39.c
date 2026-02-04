#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *i__;
extern doublereal *d__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal tau;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write with indirect read using offset indexing
    integer base = *i__;
    for (j = 1; j <= i__1; ++j) {
        // Use a fixed offset pattern: access d__ with index shifted by j % 4
        integer offset = (j % 4) + 1;
        if (offset <= i__1) {
            delta[j] = d__[offset] - d__[base] - tau;
        } else {
            delta[j] = d__[j] - d__[base] - tau;
        }
    }
}
