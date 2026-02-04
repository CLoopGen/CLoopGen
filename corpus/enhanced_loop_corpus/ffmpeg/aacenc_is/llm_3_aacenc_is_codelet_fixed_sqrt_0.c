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
    // Variant 2: Consecutive Access Pattern with Local Buffer Simulation
    // Simulate consecutive memory accesses by precomputing bit_mask values into a local array
    // and iterating through them consecutively, even though original logic is bit-dependent
    int max_iter = shift2;
    int mask_buffer[32]; // Assuming shift2 <= 32 for safety
    int current_mask = bit_mask;

    // Precompute masks with consecutive storage (simulating transformed access pattern)
    for (int j = 0; j < max_iter; j++) {
        mask_buffer[j] = current_mask;
        current_mask >>= 1;
    }

    // Now loop with consecutive array access
    for (i = 0; i < max_iter; i++) {
        guess = retval + mask_buffer[i];
        accu = (int64_t)guess * guess;
        square = (int)((accu + mask_buffer[i]) >> bits);
        if (x >= square)
            retval += mask_buffer[i];
    }
    // Update global bit_mask to reflect final state (optional side effect consistency)
    bit_mask = (bit_mask >> max_iter);
}
