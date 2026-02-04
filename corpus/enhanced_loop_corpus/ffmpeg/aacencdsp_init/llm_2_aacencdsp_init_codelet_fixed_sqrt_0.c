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
    // Variant 1: Strided memory access pattern simulation via index scaling (simulating strided array-like access)
    for (i = 0; i < shift2; i++) {
        int idx = i * 2; // Simulate strided access (stride of 2)
        guess = retval + (bit_mask >> (idx % 4)); // Use scaled index to modify bit_mask access pattern
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
        bit_mask >>= 1;
    }
}
