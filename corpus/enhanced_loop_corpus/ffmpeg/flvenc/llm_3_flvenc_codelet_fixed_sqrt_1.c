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
    // Variant 2: Consecutive array access pattern with prefetching simulation
    // Use consecutive array elements to simulate linear memory traversal and improve cache locality
    const int N = 128;
    int history_retval[N];   // Circular buffer to store past retval values
    int history_square[N];   // Store computed squares consecutively
    int ptr = 0;             // Pointer for circular write

    // Initialize history arrays
    for (int j = 0; j < N; j++) {
        history_retval[j] = retval;
        history_square[j] = 0;
    }

    for (i = 0; i < shift2; i++) {
        // Consecutive write into circular buffer (simulates streaming write pattern)
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);

        // Store in consecutive memory locations
        history_retval[ptr] = retval;
        history_square[ptr] = square;

        // Use previous stored value to influence decision (simulates data dependency chain)
        if (x >= history_square[(ptr - 1 + N) % N])
            retval += bit_mask;

        bit_mask >>= 1;
        ptr = (ptr + 1) % N; // Move pointer forward consecutively
    }
}
