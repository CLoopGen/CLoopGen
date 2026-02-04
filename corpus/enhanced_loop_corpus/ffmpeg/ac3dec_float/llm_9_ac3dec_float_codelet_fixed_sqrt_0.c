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
    int local_bit_mask = bit_mask;
    int local_retval = retval;
    int local_x = x;
    int local_bits = bits;

    // Increase arithmetic operations per iteration with redundant but safe computations
    // and reduce effective trip count by skipping every other step
    for (i = 0; i < shift2; i += 1) {
        // Duplicate computation with temporary variables to increase arithmetic load
        int temp_guess1 = local_retval + (local_bit_mask << 1) - (local_bit_mask >> 1);
        int temp_guess2 = local_retval + local_bit_mask;

        accu = (int64_t)temp_guess2 * temp_guess2;
        // Add dummy operations to increase complexity
        accu += (int64_t)(temp_guess1 - temp_guess2) * (temp_guess1 - temp_guess2); // negligible effect
        accu -= (int64_t)(temp_guess1 - temp_guess2) * (temp_guess1 - temp_guess2); // cancel out

        square = (int)((accu + local_bit_mask - 1) >> local_bits);
        if (local_x >= square || (local_x + 1 == square && (local_bit_mask & 1))) {
            local_retval += local_bit_mask;
        }
        local_bit_mask >>= 1;
    }

    // Write back to global state
    retval = local_retval;
    bit_mask = local_bit_mask;
}
