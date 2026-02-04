#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer i__;
extern doublereal tmp[4];
extern doublereal temp;
extern integer jpiv[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= 6; ++i__) {
    integer idx1 = 4 - (i__ % 3 + 1) - 1;
    integer idx2 = jpiv[idx1] - 1;
    if (jpiv[idx1] != 4 - (i__ % 3 + 1)) {
        temp = tmp[idx1];
        tmp[idx1] = tmp[idx2];
        tmp[idx2] = temp;
    }
}
}
