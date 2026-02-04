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
    // Variant 2: Consecutive memory access pattern using a simulated buffer to store intermediate masks
    // We precompute bit masks into a local array and access them consecutively
    int mask_buffer[32];  // Assuming shift2 <= 32
    int temp_mask = bit_mask;
    int actual_size = 0;

    // Pre-fill the buffer with consecutive bit mask values
    for (int j = 0; j < shift2 && actual_size < 32; j++) {
        mask_buffer[actual_size++] = temp_mask;
        temp_mask >>= 1;
    }

    // Main loop with consecutive array access
    for (i = 0; i < actual_size; i++) {
        int local_bit_mask = mask_buffer[i];  // Consecutive access
        guess = retval + local_bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + local_bit_mask) >> bits);
        if (x >= square)
            retval += local_bit_mask;
    }
}
