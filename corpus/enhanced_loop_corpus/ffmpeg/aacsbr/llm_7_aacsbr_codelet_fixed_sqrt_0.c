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
    int speculative_add = 0;
    int64_t accu1, accu2;
    int square1, square2;
    int guess1, guess2;
    for (i = 0; i < shift2; i += 2) {
        guess1 = retval + bit_mask;
        accu1 = (int64_t)guess1 * guess1;
        square1 = (int)((accu1 + bit_mask) >> bits);

        if (i + 1 < shift2) {
            int next_bit_mask = bit_mask >> 1;
            guess2 = retval + next_bit_mask;
            accu2 = (int64_t)guess2 * guess2;
            square2 = (int)((accu2 + next_bit_mask) >> bits);

            if (x >= square2)
                speculative_add |= (next_bit_mask);
        }

        if (x >= square1)
            retval += bit_mask;

        bit_mask >>= 1;
        if (i + 1 < shift2)
            retval += (speculative_add & bit_mask);
        speculative_add = 0;
    }
}
