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
    // Variant 1: Consecutive memory access pattern using a forward loop with adjusted indexing
    for (i__ = 0; i__ < 3; ++i__) {
        int idx = 2 - i__; // Reverse index to simulate original 3,2,1 traversal on tmp[3,2,1]
        if (jpiv[idx] != idx + 1) {
            temp = tmp[idx];
            tmp[idx] = tmp[jpiv[idx] - 1];
            tmp[jpiv[idx] - 1] = temp;
        }
    }
}
