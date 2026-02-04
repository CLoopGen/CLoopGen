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
    for (i = 0; i < shift2 && bit_mask > 0; i++) { // Increased condition complexity, but reduced effective depth by combining logic
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
        bit_mask >>= 1;
    }
    // Note: Though not adding a new loop, this variant simulates reduced nesting potential by consolidating exit conditions,
    // effectively simplifying the control flow structure compared to deeper or more complex nests.
}
