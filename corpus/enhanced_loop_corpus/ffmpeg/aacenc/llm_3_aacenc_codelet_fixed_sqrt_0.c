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
    // Variant 2: Consecutive (sequential) array access pattern using a buffer to stage operations
    // All computations are first stored in consecutive array locations before final reduction
    int history_size = 32;
    int temp_vals[32] = {0}; // Buffer for sequential updates
    int j;

    temp_vals[0] = retval;

    for (j = 0; j < shift2 && j < history_size; j++) {
        // Use consecutive elements in temp_vals as working storage
        guess = temp_vals[j] + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);

        if (x >= square)
            temp_vals[j + 1] = temp_vals[j] + bit_mask;
        else
            temp_vals[j + 1] = temp_vals[j];

        bit_mask >>= 1;
    }

    // Final update from the last valid state in the sequence
    retval = temp_vals[shift2 < history_size ? shift2 : history_size - 1];
}
