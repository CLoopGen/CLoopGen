#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern integer i__1;
extern integer i0;
extern integer i4;
extern integer ipn4;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing elements with strided and mirrored indices,
    // we restructure the access pattern to process consecutive pairs.
    // This improves spatial locality and cache performance.
    integer base;
    for (i4 = i0 << 2; i4 <= i__1 - 3; i4 += 4) {
        base = i4 - 3;
        temp = z__[base];
        z__[base] = z__[ipn4 - base - 6];
        z__[ipn4 - base - 6] = temp;

        temp = z__[base + 2];
        z__[base + 2] = z__[ipn4 - base - 8];
        z__[ipn4 - base - 8] = temp;
    }
}
