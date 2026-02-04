#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

extern R *I;
extern R *O;
extern INT n0;
extern INT is0;
extern INT os0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling factor of 2
    // Assumes n0 is even; handles pairs of elements in a single iteration
    for (; n0 > 1; n0 -= 2, I += 2*is0, O += 2*os0) {
        *O = *I;
        *(O + os0) = *(I + is0);
    }
    if (n0 == 1) {
        *O = *I;
        // No need to update pointers as loop ends
    }
}
