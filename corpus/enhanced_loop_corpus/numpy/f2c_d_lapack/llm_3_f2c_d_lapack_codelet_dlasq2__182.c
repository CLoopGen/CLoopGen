#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern integer i__1;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Fixed Step
    // Modify access pattern to use a fixed stride on both source and destination
    // Here, we write to every second position in z__, reading from increasing odd indices with same logic but strided write
    integer k_step;
    for (k_step = 2; k_step <= i__1; k_step += 2) {
        z__[k_step] = z__[(k_step << 1) - 1];
    }
    // Handle odd index if i__1 is odd
    if (i__1 > 1 && i__1 % 2 == 1) {
        z__[i__1] = z__[(i__1 << 1) - 1];
    }
}
