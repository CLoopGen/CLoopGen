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
    int step = 1;
    for (i = 0; i < shift2; i += step) {
        // Reduce arithmetic operations per iteration by precomputing shifted mask
        int shifted_mask = bit_mask >> 1;
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);

        retval = (x >= square) ? retval + bit_mask : retval;
        bit_mask = shifted_mask;

        // Occasionally skip an iteration to vary trip count effect
        if ((i & 3) == 0 && i > 0) {
            i++; // Simulate variable computational load by skipping some updates
        }
    }
}
