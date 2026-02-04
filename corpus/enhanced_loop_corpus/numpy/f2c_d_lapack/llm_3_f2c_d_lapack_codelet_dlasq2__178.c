#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Offset Bases
    // Reformulate array accesses to use two separate strided streams:
    // one for even positions and one for odd, simulating a de-interleaved write pattern.
    // This changes the access pattern to stride-2 writes on two virtual sub-arrays.
    integer even_base, odd_base;
    for (k = *n << 1; k >= 2; k -= 2) {
        even_base = (k >> 1) & ~1;  // Normalize index for even stream
        odd_base  = (k >> 1) |  1;  // Normalize index for odd stream

        // Map original logic into strided even/odd lanes
        z__[even_base * 4 + 0] = 0.0;            // was z__[k*2]
        z__[odd_base  * 4 - 3] = z__[k];        // was z__[(k<<1)-1]
        z__[even_base * 4 - 2] = 0.0;            // was z__[(k<<1)-2]
        z__[odd_base  * 4 - 5] = z__[k - 1];    // was z__[(k<<1)-3]
    }
}
