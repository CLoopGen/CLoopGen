#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bits;
extern int shift;
extern int coeff_mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_shift = 0;
    for (shift = 0; temp_shift < 7 && bits + shift < 16 && !(coeff_mask & (1 << shift)); temp_shift++, shift++) {
        // Introduce temporary variable to break direct loop-carried WAW dependency on 'shift'
        // Now 'shift' is updated only once per iteration, and loop bound uses a separate counter
    }
}
