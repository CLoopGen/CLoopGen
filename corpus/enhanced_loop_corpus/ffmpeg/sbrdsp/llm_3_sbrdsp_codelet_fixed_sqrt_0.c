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
    // Variant 2: Consecutive memory access pattern via simulated buffer
    // Use a temporary array to stage variable values and update them in bulk per iteration
    int buffer[4]; // Simulated storage: [retval, bit_mask, guess, square]

    for (i = 0; i < shift2; i++) {
        // Pack current values into buffer in consecutive order
        buffer[0] = retval;
        buffer[1] = bit_mask;
        buffer[2] = guess;
        buffer[3] = square;

        // Operate using consecutive accesses from buffer
        guess = buffer[0] + buffer[1];
        accu = (int64_t)guess * guess;
        square = (int)((accu + buffer[1]) >> bits);

        if (x >= square)
            retval = buffer[0] + buffer[1]; // update retval
        else
            retval = buffer[0];

        bit_mask = buffer[1] >> 1; // update bit_mask
    }
}
