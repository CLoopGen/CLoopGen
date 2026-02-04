#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; ++i) {
    // Reorder computations to eliminate some RAW dependencies and change evaluation order
    // Also remove loop-carried dependencies entirely
    const int t0 = tmp[0 + i], t4 = tmp[4 + i], t8 = tmp[8 + i], t12 = tmp[12 + i];
    // Compute differences first, removing original RAW sequence
    const int a3 = t0 - t8;
    const int a2 = t4 - t12;
    const int a0 = t0 + t8;
    const int a1 = t4 + t12;
    // Regroup operations to break dependency chains
    const int sum_aa = a0 + a1;
    const int diff_aa = a0 - a1;
    const int sum_ab = a3 + a2;
    const int diff_ab = a3 - a2;
    const int b0 = sum_aa;
    const int b1 = sum_ab;
    const int b2 = diff_ab;
    const int b3 = diff_aa;
    // Eliminate all inter-iteration dependencies and collapse temporaries early
}
}
