#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bits;
extern int shift;
extern int coeff_mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_bits = bits;  // Introduce local copy to create RAW dependency
    for (shift = 0; shift < 7 && local_bits + shift < 16; shift++) {
        if (coeff_mask & (1 << shift)) {
            break;  // Eliminate the anti-dependence by moving condition check inside
        }
        // Loop-carried dependence on 'shift' remains, but condition evaluation is restructured
        // This removes the combined condition, altering data flow while preserving semantics
    }
    // Note: 'shift' still holds the correct exit value as in original
}
