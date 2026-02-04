#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int shift2;
extern int x;
extern int bits;
extern int retval;
extern int bit_mask;
extern int guess;
extern int square;
extern int i;
extern int64_t accu;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_bit_mask = bit_mask;
    int local_retval = retval;
    for (i = 0; i < shift2; i++) {
        int guess_val = local_retval + local_bit_mask;
        accu = (int64_t)guess_val * guess_val;
        int square_val = (int)((accu + local_bit_mask) >> bits);
        if (x >= square_val)
            local_retval += local_bit_mask;
        local_bit_mask >>= 1;
    }
    retval = local_retval;
}
