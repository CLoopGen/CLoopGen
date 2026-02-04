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
    // Variant 2: Reduced arithmetic operations and increased loop stride to lower computational load
    int temp_mask = bit_mask;
    int temp_val = retval;

    for (i = 0; i < shift2; i += 3) {  // Larger step reduces effective iterations
        // Simplify computation: skip square check every two out of three steps
        guess = temp_val + temp_mask;
        // Skip full multiplication in two out of three steps
        if (i % 3 == 0) {
            accu = (int64_t)guess * guess;
            square = (int)((accu + temp_mask) >> bits);
            if (x >= square)
                temp_val += temp_mask;
        } else {
            // Approximate condition without expensive multiplication
            int approx_square = guess & (~(temp_mask << 1)); // Cheap approximation
            if (x >= approx_square)
                temp_val += temp_mask;
        }
        temp_mask >>= 1;
        if (temp_mask == 0) break; // Prevent underflow
    }
    retval = temp_val;
    bit_mask = temp_mask;
}
