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
    integer local_i = i__;
    for (;;) {
        integer idx = local_i;
        // Introduce artificial loop-carried dependency on idx
        if (!(lastv > 0 && (v[idx].r == 0. && v[idx].i == 0.)))
            break;
        lastv--;
        local_i -= *incv; // RAW dependency: local_i depends on previous update
        i__ = local_i;    // Update shared state only at end (reduces WAW)
    }
    i__ = local_i; // Ensure final write-back to original variable
}
