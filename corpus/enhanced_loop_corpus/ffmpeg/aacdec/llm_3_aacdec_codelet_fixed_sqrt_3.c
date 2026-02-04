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
    // Variant 2: Consecutive access via unrolled memory-like access pattern (loop unrolling to simulate bulk access)
    // Unroll the loop by a factor of 2 to create consecutive operations and improve spatial locality
    guess = retval + bit_mask;
    accu = (int64_t)guess * guess;
    square = (int)((accu + bit_mask) >> bits);
    if (x >= square)
        retval += bit_mask;
    bit_mask >>= 1;

    for (i = 1; i < shift2; i++) {
        // Simulate consecutive access by reusing intermediate values immediately
        int next_bit_mask = bit_mask >> 1;
        int next_guess = retval + next_bit_mask;
        int64_t next_accu = (int64_t)next_guess * next_guess;
        int next_square = (int)((next_accu + next_bit_mask) >> bits);

        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);

        if (x >= square)
            retval += bit_mask;

        // Update for next iteration
        bit_mask = next_bit_mask;
        guess = next_guess;
        accu = next_accu;
        square = next_square;
    }

    // Final iteration cleanup if shift2 >= 1
    if (shift2 > 0) {
        if (x >= square)
            retval += bit_mask;
    }
}
