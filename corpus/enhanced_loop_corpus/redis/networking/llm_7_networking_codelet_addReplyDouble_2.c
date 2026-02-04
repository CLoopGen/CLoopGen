#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char dbuf[5152];
extern  int dlen;
extern int digits;
extern int start;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Introduce artificial loop-carried dependency via an accumulator
    // to create a RAW hazard across iterations. Also unroll by factor of 2 for variation.
    // We simulate a checksum over written digits while writing them, creating a 
    // sequential dependency that prevents reordering.

    int val = dlen;
    int acc = 0;  // Loop-carried dependency: each iteration depends on previous acc
    int i = digits;

    // Fully unrolled style with manual handling (assuming digits is small and even)
    // We process two digits at a time if possible, but maintain correct order
    for (; i >= 2 && val >= 10; i -= 2, val /= 100) {
        // Higher digit (tens place)
        char high = "0123456789"[(val / 10) % 10];
        // Lower digit (ones place)
        char low = "0123456789"[val % 10];

        // Artificial dependency: use accumulator to force ordering
        acc = (acc + high) & 0xFF;
        dbuf[start + i - 1] = high;

        acc = (acc + low) & 0xFF;
        dbuf[start + i] = low;
    }

    // Handle remaining single digit if needed
    for (; i > 0 && val; --i, val /= 10) {
        char c = "0123456789"[val % 10];
        acc = (acc + c) & 0xFF;
        dbuf[start + i] = c;
    }

    // Ensure acc is used to prevent compiler elimination (volatile effect simulated)
    // In real code, this might feed into another computation
    (void)acc;
}
