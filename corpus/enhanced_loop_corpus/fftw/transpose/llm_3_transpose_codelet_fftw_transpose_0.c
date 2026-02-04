#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

extern R *I;
extern INT n;
extern INT s0;
extern INT s1;
extern INT i0;
extern INT i1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Precomputed Base Offsets
    for (i1 = 1; i1 < n; ++i1) {
        INT base1 = i1 * s0;
        INT base2 = i1 * s1;
        for (i0 = 0; i0 < i1; ++i0) {
            INT offset_low = i0 * s1;
            INT offset_high = i0 * s0;
            R x0 = I[base1 + offset_low];
            R y0 = I[base2 + offset_high];
            I[base2 + offset_high] = x0;
            I[base1 + offset_low] = y0;
        }
    }
}
