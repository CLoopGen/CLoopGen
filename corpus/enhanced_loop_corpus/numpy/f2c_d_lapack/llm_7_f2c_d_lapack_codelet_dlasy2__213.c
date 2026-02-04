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
    doublereal snapshot[3];
    for (i__ = 1; i__ <= 3; ++i__) {
        integer read_idx = 4 - i__ - 1;
        snapshot[i__ - 1] = tmp[read_idx];
    }
    for (i__ = 1; i__ <= 3; ++i__) {
        integer orig_pos = 4 - i__ - 1;
        integer pivot_pos = jpiv[orig_pos] - 1;
        if (jpiv[orig_pos] != 4 - i__) {
            tmp[orig_pos] = snapshot[3 - i__]; 
            tmp[pivot_pos] = snapshot[i__ - 1]; 
        }
    }
}
