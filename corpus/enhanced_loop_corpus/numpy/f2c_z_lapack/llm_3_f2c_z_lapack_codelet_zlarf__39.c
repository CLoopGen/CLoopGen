#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *v;
extern integer *incv;
extern integer i__1;
extern integer i__;
extern integer lastv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal using offset-based indexing
    // Instead of relying on index `i__` which may be strided, we reframe access to be consecutive
    // by introducing a local offset that traverses backward consecutively through the array
    // This simulates a transformed loop where access is coalesced and unit-stride

    integer offset = lastv - 1; // Start from last valid position with unit stride
    for (;;) {
        i__1 = offset; // Now using consecutive index
        if (!(lastv > 0 && (v[i__1].r == 0. && v[i__1].i == 0.)))
            break;
        --lastv;
        --offset; // Decrement by 1 for consecutive access
        i__ = offset; // Update global-like index to reflect new position
    }
}
