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



void loop(){
    // Variant 2: Consecutive memory access pattern using a simulated buffer to create sequential data flow
    int history[8]; // Local buffer to simulate consecutive memory accesses
    for (i = 0; i < shift2 && i < 8; i++) {
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square) {
            retval += bit_mask;
            history[i] = retval; // Sequential write to local array
        } else {
            history[i] = bit_mask; // Maintain consecutive access regardless of condition
        }
        bit_mask >>= 1;
    }
    // Ensure no unused code is optimized out (minimal side-effect preservation)
    if (shift2 > 8) retval += history[7];
}
