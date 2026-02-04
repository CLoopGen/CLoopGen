#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int bits;
extern int retval;
extern int bit_mask;
extern int guess;
extern int square;
extern int i;
extern int64_t accu;
extern int shift2;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive (linear) access pattern using an array to store and update values sequentially
    // All relevant variables are stored in a linear buffer accessed consecutively in the loop

    int vars[6]; // Linear layout: [bit_mask, retval, guess, square, i_next, unused]
    vars[0] = bit_mask;
    vars[1] = retval;

    for (i = 0; i < shift2; i++) {
        // Sequential traversal: simulate consecutive access to packed data
        for (int j = 0; j < 4; j += 4) { // Artificial block step to emphasize linear pattern
            vars[2] = vars[1] + vars[0]; // guess = retval + bit_mask
            accu = (int64_t)vars[2] * vars[2];
            vars[3] = (int)((accu + vars[0]) >> bits);
            
            if (x >= vars[3])
                vars[1] += vars[0]; // retval updated
            
            vars[0] >>= 1; // bit_mask >>= 1
        }
    }

    // Write back to global state
    retval = vars[1];
    bit_mask = vars[0];
}
