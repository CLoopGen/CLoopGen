#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal phi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal using an index remapping (reverse order via forward loop with inverted index)
    // Instead of decrementing from n to i__1, we compute a consecutive forward loop and map index accordingly.
    integer length = *n - i__1 + 1;
    for (j = 0; j < length; ++j) {
        integer idx = *n - j;  // Reverse mapping: simulate descending order
        phi += z__[idx] * z__[idx] / (work[idx] * delta[idx]);
    }
    // Note: 'j' is repurposed as a forward counter; final value may differ, but loop logic remains equivalent.
}
