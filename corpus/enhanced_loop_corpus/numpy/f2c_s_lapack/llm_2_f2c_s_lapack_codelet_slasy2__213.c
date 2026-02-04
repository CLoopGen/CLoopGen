#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer i__;
extern real tmp[4];
extern real temp;
extern integer jpiv[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using a forward loop with index remapping
    integer indices[3] = {2, 1, 0}; // Maps 4 - i__ - 1 for i__ from 1 to 3
    for (i__ = 0; i__ < 3; ++i__) {
        integer idx = indices[i__];
        if (jpiv[idx] != idx + 1) {
            temp = tmp[idx];
            tmp[idx] = tmp[jpiv[idx] - 1];
            tmp[jpiv[idx] - 1] = temp;
        }
    }
}
