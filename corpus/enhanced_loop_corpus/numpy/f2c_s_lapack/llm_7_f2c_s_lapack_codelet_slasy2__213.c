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
    real scratch[3];
    integer store_idx[3];
    integer needs_swap[3];
    for (i__ = 1; i__ <= 3; ++i__) {
        integer idx = 4 - i__ - 1;
        needs_swap[i__ - 1] = (jpiv[idx] != 4 - i__) ? 1 : 0;
        store_idx[i__ - 1] = idx;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
        if (needs_swap[i__ - 1]) {
            integer idx1 = store_idx[i__ - 1];
            integer idx2 = jpiv[idx1] - 1;
            scratch[i__ - 1] = tmp[idx1];
            tmp[idx1] = tmp[idx2];
        }
    }
    for (i__ = 1; i__ <= 3; ++i__) {
        if (needs_swap[i__ - 1]) {
            integer idx1 = store_idx[i__ - 1];
            integer idx2 = jpiv[idx1] - 1;
            tmp[idx2] = scratch[i__ - 1];
        }
    }
}
