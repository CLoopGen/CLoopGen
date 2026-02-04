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
    doublereal temp_local;
    for (i__ = 1; i__ <= 3; ++i__) {
        integer idx = 4 - i__ - 1;
        integer jidx = jpiv[idx] - 1;
        if (jpiv[idx] != 4 - i__) {
            temp_local = tmp[idx];
            tmp[idx] = tmp[jidx];
            tmp[jidx] = temp_local;
        }
    }
}
