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
    // Variant 2: Consecutive memory access pattern using a simulated buffer to store intermediate states
    // All operations are performed in-order with consecutive writes to local arrays
    int history_retval[64];
    int history_bit_mask[64];
    int j = 0;

    bit_mask >>= 0; // Ensure initial state

    for (i = 0; i < shift2; i++) {
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);

        if (x >= square)
            retval += bit_mask;

        // Store each state consecutively
        history_retval[j] = retval;
        history_bit_mask[j] = bit_mask;
        j++;

        bit_mask >>= 1;
    }

    // Dummy use of history to prevent optimization away
    if (j > 0) {
        retval = history_retval[j-1];
        bit_mask = history_bit_mask[j-1];
    }
}
